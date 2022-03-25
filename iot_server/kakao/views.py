from django.shortcuts import render

from django.views.generic import TemplateView, FormView
import json
import requests
from django.contrib import messages
from .forms import KaKaoTalkForm

client_id = "레스트api키"
class KakaoLoginView(TemplateView):
  template_name = "kakao_login.html"
  def get_context_data(self, **kwargs):
    context = super().get_context_data(**kwargs)
    context["client_id"]=client_id
    return context

class KakaoAuthView(TemplateView):
  template_name = "kakao_token.html"
  def get_context_data(self, **kwargs):
    context = super().get_context_data(**kwargs)
    code = self.request.GET['code']
    token = self.getAccessToken(code)
    context["client_id"] = client_id
    context["token"] = token
    self.save_access_token(token["access_token"]) #파일로도 저장
    return context

  def getAccessToken(self,code):
    url = "https://kauth.kakao.com/oauth/token"
    payload = "grant_type=authorization_code"
    payload += "&client_id="+client_id
    payload += "&redirect_url=http://서버아이피:8000/oauth&code="+code
    headers={
      'Content-Type':"application/x-www-form-urlencoded",
      "Cache-Control":"no-cache",
    }
    response = requests.post(url, data=payload, headers=headers)
    return response.json()

  def save_access_token(self, access_token):
    with open("access_token.txt", "w") as f:
      f.write(access_token)


class KakaoTalkView(FormView):
  form_class = KaKaoTalkForm
  template_name = "kakao_form.html"
  success_url = "/kakao/talk"
  def form_valid(self, form):
    res, text = form.send_talk()
    if res.json().get('result_code') == 0:
      messages.add_message(self.request, messages.SUCCESS, "메시지 전송 성공 : " + text)
    else:
      messages.add_message(self.request, messages.ERROR, "메시지 전송 실패 : " + str(res.json()))
    return super().form_valid(form)


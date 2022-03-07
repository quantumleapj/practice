// CdS 조도센서에 걸리는 전압과 A/D 변환값 확인
// 밝으면 저항이 작아지므로 걸리는 전압이 작아지고
// 어두우면 저항이 커지므로 걸리는 전압이 커지게 된다.
const byte cds = A0;
void setup()
{
  Serial.begin(115200);
}
void loop()
{
  int ad_cds;
  float v_cds;
  ad_cds = analogRead(cds);
  v_cds = (float)ad_cds / 1024.0 * 5;
  Serial.print("AD_CDS = ");
  Serial.println(ad_cds);
  Serial.print("V_CDS = ");
  Serial.println(v_cds);
  Serial.println(" ");
  delay(1000);
}
import cv2
image_file = './data/lena.jpg'
img = cv2.imread(image_file)
cv2.imwrite('./data/Lena.bmp', img) #압축없음
cv2.imwrite('./data/Lena.png', img) #디폴트 3
cv2.imwrite('./data/Lena2.png', img, [cv2.IMWRITE_PNG_COMPRESSION, 9])
cv2.imwrite('./data/Lena2.jpg', img, [cv2.IMWRITE_JPEG_QUALITY, 90])

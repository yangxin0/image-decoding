import cv2

img = cv2.imread("/Users/yangxin/Downloads/20201007113938_205.mp4_00005875.raw.png.bmp", cv2.IMREAD_COLOR)
for i in range(1080):
    for j in range(1920):
        (B, G, R) = img[i, j, :]
        if B == 83 and G == 83 and R == 77:
            print(i, j, B, G, R)

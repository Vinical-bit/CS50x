import qrcode

img = qrcode.make("https://youtu.be/xvFZjo5PgG0?si=xncw4KfjmpbHVOO2")
img.save("qr.png", "PNG")
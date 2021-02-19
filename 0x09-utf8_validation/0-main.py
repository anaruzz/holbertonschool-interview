#!/usr/bin/python3
"""
Main file for testing
"""

validUTF8 = __import__('0-validate_utf8').validUTF8

data = [65]
print(1, validUTF8(data)," == True")

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(2, validUTF8(data)," == True")

data = [229, 65, 127, 256]
print(3, validUTF8(data)," == False")

data = [467, 133, 108]
maskeddata = [n & 255 for n in data]
print(maskeddata)
print(4, validUTF8(data)," == True")
data = [240, 188, 128, 167]
print(5, validUTF8(data)," == True")
data = [235, 140]
print(6, validUTF8(data)," == False")
data = [345, 467]
print(7, validUTF8(data)," == False")
data = [250, 145, 145, 145, 145]
print(8, validUTF8(data)," == False")
data = [0, 0, 0, 0, 0, 0]
print(9, validUTF8(data)," == True")
data = []
print(10, validUTF8(data)," == True")

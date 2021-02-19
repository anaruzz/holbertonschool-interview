#!/usr/bin/python3
"""
Script that determines if a given data set represents a valid
UTF-8 encoding
"""


def validUTF8(data):
    """
    Returns: True if utf encoding is valid, false otherwise
    """
    masked = [i & 255 for i in data]
    try:
        bytearray(masked).decode("UTF-8")
        return True
    except Exception as e:
        return False

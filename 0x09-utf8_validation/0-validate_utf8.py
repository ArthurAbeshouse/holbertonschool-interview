#!/usr/bin/python3
"""method that determines if a given data set represents
a valid UTF-8 encoding"""


def validUTF8(data):
    num_of_bytes = 0
    ref_data = []

    if data is None:
        return False

    """Validates int array for UTF-8"""
    for num_of_bytes in data:
        ref_data.append(num_of_bytes & 255)

    byte_data = bytes(ref_data)

    try:
        byte_data.decode()
    except UnicodeDecodeError:
        return False

    return True

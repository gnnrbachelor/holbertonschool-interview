#!/usr/bin/python3
""" UTF-8 Validation """


def validUTF8(data):
    """Checks for UTF-8 compliance"""
    try:
        # bytes.decode() default args included for clarity
        bytes(data).decode(encoding='utf-8', errors='strict')
    except (ValueError, UnicodeDecodeError):
        return False
    return True



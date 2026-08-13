#!/usr/bin/python3
"""
User class
"""
import hashlib


class User:
    """ User class """

    def __init__(self):
        """ Initialize User """
        self.__password = None

    @property
    def password(self):
        """ Getter for password """
        return self.__password

    @password.setter
    def password(self, password):
        """ Setter for password (hashes password with MD5) """
        if password is None or type(password) != str:
            self.__password = None
        else:
            self.__password = hashlib.md5(password.encode()).hexdigest()

    def is_valid_password(self, password):
        """ Check if password matches hashed password """
        if password is None or type(password) != str:
            return False
        if self.__password is None:
            return False
        # Fix: Return True when MD5 hash of input equals stored __password
        return self.__password == hashlib.md5(password.encode()).hexdigest()


if __name__ == "__main__":
    print("Test User")
    user = User()
    user.password = "root" 
    if not user.is_valid_password("root"):
        print("is_valid_password should return True if it's the right password")

    if user.is_valid_password("root1"):
        print("is_valid_password should return False if it's not the right password")

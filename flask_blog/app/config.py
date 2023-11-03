import os

base_url = os.path.dirname(os.path.abspath(__name__))
class Config:
    DEBUG = True
    SQLALCHEMY_TRACK_MODIFICATIONS = False
    SQLALCHEMY_DATABASE_URI = 'sqlite:///' + os.path.join(base_url, 'Database.db')
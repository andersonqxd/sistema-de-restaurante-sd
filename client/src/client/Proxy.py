import json
from .Client import Client

SERVER_IP = '127.0.0.1'
SERVER_PORT = 7000


class Proxy: 
    def __init__(self):
        self.__client = Client(SERVER_IP, SERVER_PORT)



    def get_tables(self) -> dict:
        self.__client.send_request(json.dumps({}))

        return json.loads(self.__client.get_response())

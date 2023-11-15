import json
from .Client import Client

SERVER_IP = '127.0.0.1'
SERVER_PORT = 7000


GET_TABLES_RESTURANT = 1
RESERVED_TABLE_RESTAURANT = 2
CHECK_STATUS_ORDER = 3
MAKE_WISH_RESTAURANT = 4
GET_MENU_RESTAURANT = 5

class Proxy: 
    def __init__(self):
        self.__client = Client(SERVER_IP, SERVER_PORT)



    def get_tables(self) -> dict:
        self.__client.send_request(json.dumps({}), GET_TABLES_RESTURANT)

        return json.loads(self.__client.get_response().get_arguments())
    

    def reserved_table(self, table: dict) -> dict:
        self.__client.send_request(json.dumps(table), RESERVED_TABLE_RESTAURANT)

        return json.loads(self.__client.get_response().get_arguments())
    

    def get_menu(self) -> dict:
        self.__client.send_request(json.dumps({}), GET_MENU_RESTAURANT)

        return json.loads(self.__client.get_response().get_arguments())
    

    def make_wish(self, products: list, table_id: int) -> dict:
        self.__client.send_request(json.dumps({ 'table_id': table_id, 'products': products }), MAKE_WISH_RESTAURANT)

        return json.loads(self.__client.get_response().get_arguments())
    

    def check_status_order(self, table_id: int) -> dict:
        self.__client.send_request(json.dumps({ 'table_id': table_id }), CHECK_STATUS_ORDER)

        return json.loads(self.__client.get_response().get_arguments())

import json
from .Client import Client

SERVER_IP = '127.0.0.1'
SERVER_PORT = 7000


GET_TABLES_RESTAURANT = 1
RESERVED_TABLE_RESTAURANT = 2
CHECK_STATUS_ORDER = 3
MAKE_WISH_RESTAURANT = 4
GET_MENU_RESTAURANT = 5

class Proxy: 
    def __init__(self):
        self.__client = Client(SERVER_IP, SERVER_PORT)


    def get_tables(self) -> dict:
        """
        Obtém informações sobre as mesas do restaurante.

        Returns:
            dict: Um dicionário contendo informações sobre as mesas do restaurante.
        """

        self.__client.send_request(json.dumps({}), GET_TABLES_RESTAURANT)
        
        return json.loads(self.__client.get_response().get_arguments())
    

    def reserved_table(self, table: dict) -> dict:
        """
        Reserva uma mesa no restaurante com base nos detalhes fornecidos.

        Args:
            table (dict): Um dicionário contendo detalhes sobre a mesa a ser reservada.

        Returns:
            dict: Um dicionário contendo informações sobre a reserva da mesa.
        """

        self.__client.send_request(json.dumps(table), RESERVED_TABLE_RESTAURANT)
        
        return json.loads(self.__client.get_response().get_arguments())
    

    def get_menu(self) -> dict:
        """
        Obtém o menu do restaurante.

        Returns:
            dict: Um dicionário contendo informações sobre o menu do restaurante.
        """

        self.__client.send_request(json.dumps({}), GET_MENU_RESTAURANT)
        
        return json.loads(self.__client.get_response().get_arguments())
    

    def make_wish(self, products: list, table_id: int) -> dict:
        """
        Faz um pedido no restaurante com base nos produtos e na mesa fornecidos.

        Args:
            products (list): Uma lista contendo detalhes sobre os produtos a serem pedidos.
            table_id (int): O identificador da mesa para a qual o pedido será feito.

        Returns:
            dict: Um dicionário contendo informações sobre o pedido feito.
        """

        self.__client.send_request(json.dumps({'table_id': table_id, 'products': products}), MAKE_WISH_RESTAURANT)
        
        return json.loads(self.__client.get_response().get_arguments())


    def check_status_order(self, table_id: int) -> dict:
        """
        Verifica o status dos pedidos associados a uma mesa específica no restaurante.

        Args:
            table_id (int): O identificador único da mesa para a qual o status dos pedidos será verificado.

        Returns:
            dict: Um dicionário contendo informações sobre o status dos pedidos associados à mesa.
        """

        self.__client.send_request(json.dumps({'table_id': table_id}), CHECK_STATUS_ORDER)
        
        return json.loads(self.__client.get_response().get_arguments())

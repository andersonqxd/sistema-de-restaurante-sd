import socket
import json

from .Message import Message, MSG_REQUEST


class Client:
    """
    Um cliente UDP simples para enviar e receber dados por meio de uma rede.

    Esta classe fornece métodos para enviar solicitações e receber respostas usando o protocolo UDP.

    Atributos:
        __udp (socket.socket): O soquete UDP usado para comunicação.
        __ip (str): O endereço IP do servidor remoto.
        __port (int): O número da porta do servidor remoto.
        __buffer_size (int): O tamanho do buffer de recepção para dados de entrada.

    Métodos:
        __init__(self, ip: str, port: int, buffer=1024) -> None:
            Inicializa o objeto Client com o endereço IP, porta e tamanho do buffer especificados.
        
        __get_address(self):
            Retorna uma tupla contendo o endereço IP e a porta como destino.
        
        send_request(self, data: str):
            Envia uma solicitação UDP com os dados fornecidos para o servidor remoto.
        
        get_response(self) -> str:
            Recebe uma resposta do servidor remoto e a retorna como uma string codificada em UTF-8.
    """



    def __init__(self, ip: str, port: int, buffer=2024) -> None:
        """
        Inicializa um novo objeto Client.

        Args:
            ip (str): O endereço IP do servidor remoto.
            port (int): O número da porta do servidor remoto.
            buffer (int): O tamanho do buffer de recepção para dados de entrada.

        Returns:
            None
        """

        self.__udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

        self.__ip = ip
        self.__port = port

        self.__buffer_size = buffer



    def __get_address(self):
        """
        Retorna o endereço de destino como uma tupla.

        Returns:
            Tupla (str, int): O endereço IP e o número da porta.
        """

        return (self.__ip, self.__port)



    def __create_new_message(self, arguments):
        return Message(MSG_REQUEST, 1, 'restaurante', 2, arguments)



    def send_request(self, data: str):
        """
        Envia uma solicitação UDP para o servidor remoto com os dados fornecidos.

        Args:
            data (str): Os dados a serem enviados como uma string codificada em UTF-8.

        Returns:
            None
        """

        payload = json.dumps(self.__create_new_message(data).to_json())

        self.__udp.sendto(payload.encode('utf-8'), self.__get_address())


    def get_response(self) -> str:
        """
        Recebe uma resposta do servidor remoto e a retorna como uma string codificada em UTF-8.

        Returns:
            str: Os dados da resposta como uma string codificada em UTF-8.
        """

        data, addr = self.__udp.recvfrom(self.__buffer_size)

        payload_size = int.from_bytes(data[:4], 'little')

        return data[4:payload_size + 4].decode('utf-8')



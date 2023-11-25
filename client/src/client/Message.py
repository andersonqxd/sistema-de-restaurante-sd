
MSG_REQUEST = 0
MSG_REPLY = 1


class Message:
    def __init__(self, message_type: int, request_id: int, object_reference: str, method_id: int, arguments: str | None = None) -> None:
        self.__message_type = message_type
        self.__request_id = request_id
        self.__object_reference = object_reference
        self.__method_id = method_id
        self.__arguments = arguments


    def to_json(self) -> dict:
        message_json = {
            'message_type': self.__message_type,
            'request_id': self.__request_id,
            'object_reference': self.__object_reference,
            'method_id': self.__method_id,
        }

        if self.__arguments:
            message_json['arguments'] =  self.__arguments

        return message_json
    

    def get_message_type(self) -> int:
        """
        Obtém o tipo de mensagem associado à instância.

        Returns:
            int: O tipo de mensagem associado à instância.
        """
        
        return self.__message_type


    def get_request_id(self) -> int:
        """
        Obtém o identificador único da solicitação associado à instância.

        Returns:
            int: O identificador único da solicitação associado à instância.
        """

        
        return self.__request_id


    def set_request_id(self, request_id: int) -> None:
        """
        Define o identificador único da solicitação associado à instância.

        Args:
            request_id (int): O novo identificador único da solicitação.

        Returns:
            None
        """
        self.__request_id = request_id


    def get_object_reference(self) -> str:
        """
        Obtém a referência do objeto associada à instância.

        Returns:
            str: A referência do objeto associada à instância.
        """
        
        return self.__object_reference


    def get_method_id(self) -> int:
        """
        Obtém o identificador do método associado à instância.

        Returns:
            int: O identificador do método associado à instância.
        """
        
        return self.__method_id


    def get_arguments(self) -> str:
        """
        Obtém os argumentos associados à instância.

        Returns:
            str: Os argumentos associados à instância.
        """
        
        return self.__arguments

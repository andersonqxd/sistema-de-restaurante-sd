import socket


class Client:
    def __init__( self, ip: str, port: int, buffer=1024 ) -> None:
        self.__udp = socket.socket( socket.AF_INET, socket.SOCK_DGRAM )

        self.__ip = ip
        self.__port = port

        self.__buffer_size = 1024


    def __get_address( self ):
        return ( self.__ip, self.__port )


    def send_request( self, data: str ):
        self.__udp.sendto( data.encode( 'utf-8' ), self.__get_address() )


    def get_response( self ) -> str:
        data, addr = self.__udp.recvfrom( self.__buffer_size )

        print( len( data.decode( 'utf-8' ) ) )

        return data.decode( 'utf-8' )



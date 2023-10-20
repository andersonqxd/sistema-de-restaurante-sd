# cliente de teste do servirdor c++

import socket
import json


SERVER_IP = '127.0.0.1'
SERVER_PORT = 7000


data = {
    'user': {
        'name': 'Testando',
        'age': 10
    }
}


udp = socket.socket( socket.AF_INET, socket.SOCK_DGRAM )

udp.sendto( json.dumps( data ).encode( 'utf-8' ), ( SERVER_IP, SERVER_PORT ) )

print( 'send!!!' )

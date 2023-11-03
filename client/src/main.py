import json

from client.Client import Client


SERVER_IP = '127.0.0.1'
SERVER_PORT = 7000

def main() -> None:
    
    data_send = {
        'teste': 'Hello world'
    }

    client = Client(SERVER_IP, SERVER_PORT)

    client.send_request(json.dumps(data_send))
    response = client.get_response()

    print(json.loads(response))


if __name__ == '__main__':
    main()

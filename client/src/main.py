import json
from client.Proxy import Proxy


def print_tables(tables: dict) -> None:

    print('~~' * 20)
    print(f'{"ESCOLHA UMA MESA":^40}')
    print('~~' * 20)

    for table_id in tables.keys():
        print( f'\tNumero: {table_id}\n\tStatus: { "Disponivel" if not tables[table_id]["reserved"] else "Ocupada" }\n' )


def read_table() -> int:
    table_id = int(input('Numero da mesa: '))
    client_name = str(input('Nome: '))

    return { 'table_id': table_id, 'client_name': client_name }


def main() -> None:
    proxy = Proxy()

    print_tables(proxy.get_tables())

    print(proxy.reserved_table(read_table()))

    print_tables(proxy.get_tables())



if __name__ == '__main__':
    main()

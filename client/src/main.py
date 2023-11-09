import json
from client.Proxy import Proxy


def print_tables(tables: dict) -> None:

    print('~~' * 20)
    print(f'{"ESCOLHA UMA MESA":^40}')
    print('~~' * 20)

    for table_id in tables.keys():
        print( f'\tNumero: {table_id}\n\tStatus: { "Disponivel" if tables[table_id] else "Ocupada" }\n' )


def main() -> None:
    proxy = Proxy()

    tables = proxy.get_tables()

    print_tables(tables)


if __name__ == '__main__':
    main()

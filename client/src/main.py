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



def print_menu(menu: dict) -> None:
    print('~~' * 20)
    print(f'{"CARDAPIO":^40}')
    print('~~' * 20)

    for product_id in menu.keys():
        print(f'ID: {product_id}\n\tNome: {menu[product_id]["name"]}\n\tPreço: R$ {menu[product_id]["price"]:.2f}\n\tDescricao: {menu[product_id]["description"]}')
        print(f'\tPreparo: {menu[product_id]["preparation_time"]} min')


def main() -> None:
    proxy = Proxy()

    print_tables(proxy.get_tables())

    print('~~' * 20)
    print(proxy.reserved_table(read_table())["message"])
    print('~~' * 20)

    print_menu(proxy.get_menu())



if __name__ == '__main__':
    main()

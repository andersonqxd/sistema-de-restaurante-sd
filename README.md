# sistema-de-restaurante-sd

## Serviço Remoto: Sistema de restaurante
- Agendar mesa
  
> (in) Argumentos de entrada:

      Número da mesa
      Nome do cliente
      Horário
      Número de pessoas
     
>	(out) Argumento de saída

      Mesa reservada com sucesso
    
> Exceções

      Mesa ocupada
      Restaurante lotado
    
- Fazer pedido

> (in) Argumentos de entrada:

      Número da mesa
      Produtos
    
> (out) Argumento de saída

      Pedido feito com sucesso
      Tempo de espera
    
> Exceções

      Produto em falta
    
- Consultar status do pedido

> (in) Argumentos de entrada:

      Número da mesa
      Número do pedido
    
> (out) Argumento de saída

      Status do pedido (em espera, preparando, entregue).
    
> Exceções

      Mesa não encontrada
      Pedido não encontrado

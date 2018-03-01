# RT-Template-Update
  Este repositório contem arquivos atualizados e arquivos adicionais do RT-Template do professor Christian Pagot(CI-UFPB-2018) das atividades realizadas para a disciplina de Renderização Baseada em Física.

# Primeira atividade (Relacionada ao RT-Template)
  Na primeira atividade de modificações do RT-Template, o Professor nos passou o link do git para baixar e executar seu RayTracer para que os alunos implementassem, nesta primeira atividade, outra primitiva(Triangulo) e seu respectivo teste de interseção. 
  
Link do repositório do RT-Template: https://github.com/capagot/RT-Template/

Para executar o RT-Template com as minhas atualizações, basta baixar os arquivos do meu repositório RT-Template-Update(depois de ter baixado o repositório do professor e, baixado e instalado, os requisitos necessários para sua execução) e substituir os arquivos de mesmo nome, acrescentar os novos e seguir as mesmas instruções de execução do código do repositório do professor(cujo link está acima).

Em resumo, a atvidade consistia em criar outros dois arquivos: "triangle.h" e "triange.cpp"(para criar a classe Triangle, herderira da classe Primitive do RT-Template original, com o terste de interseção baseado no artigo "FastMinimum Storage Ray/Triangle Intersection" escrito por Tomas Moller e Ben Trumbore), acrescentar um include "<include> "triangle.h"" no arquivo "scene.h" do  respoistório caoagot/RT-Template e no arquivo "scene.cpp", do mesmo repositório original, acrescentar esta nova primitiva para testes, escolhi acrescentar um triângulo com seus 3 pontos com coordenadas x e y iguais as coordenadas x e y do centro de três circunferências, e o resultado desta atualização se encontra no arquivo de saída "output_image.ppm", que também se encontra neste repositório.

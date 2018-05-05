# RT-Template-Update
  Este repositório contem arquivos atualizados e arquivos adicionais do RT-Template do professor Christian Pagot(CI-UFPB-2018) das atividades realizadas para a disciplina de Renderização Baseada em Física.

## Primeira Atividade (Relacionada ao RT-Template)
  Na primeira atividade de modificações do RT-Template, o Professor nos passou o link do git para baixar e executar seu RayTracer para que os alunos implementassem, nesta primeira atividade, outra primitiva(Triangulo) e seu respectivo teste de interseção. 
  
Link do repositório do RT-Template: https://github.com/capagot/RT-Template/

Para executar o RT-Template com as minhas atualizações, basta baixar os arquivos do meu repositório RT-Template-Update(depois de ter baixado o repositório do professor e, baixado e instalado, os requisitos necessários para sua execução) e substituir os arquivos de mesmo nome, acrescentar os novos e seguir as mesmas instruções de execução do código do repositório do professor(cujo link está acima).

Em resumo, a atvidade consistia em criar outros dois arquivos: "triangle.h" e "triange.cpp"(para criar a classe Triangle, herderira da classe Primitive do RT-Template original, com o terste de interseção baseado no artigo "FastMinimum Storage Ray/Triangle Intersection" escrito por Tomas Moller e Ben Trumbore), acrescentar um include "<include> "triangle.h"" no arquivo "scene.h" do  respoistório caoagot/RT-Template e no arquivo "scene.cpp", do mesmo repositório original, acrescentar esta nova primitiva para testes, escolhi acrescentar um triângulo com seus 3 pontos com coordenadas x e y iguais as coordenadas x e y do centro de três circunferências, e o resultado desta atualização se encontra no arquivo de saída "output_image.ppm", que também se encontra neste repositório e nesta descrição, na imagem abaixo:
  
![captura de tela de 2018-03-01 08-43-24](https://user-images.githubusercontent.com/30930332/36843181-dfc3f420-1d2c-11e8-948c-cecbecf66867.jpg)

## Segunda Atividade
Na segunda atividade, foi implementada a câmera pin-hole(a qual implementei com o nome de perspective camera, por resultar numa visão perspectiva da cena), também foi acrescentada a propriedade cor às primitivas e à classe intersection_record, para que eu pudesse guardar a cor da primitiva para rasterizá-la baseado na sua cor original e sua distância até a câmera e também a leitura de arquivos obj através da biblioteca assimp.

### Implementação

Para rodar o código utilizando a biblioteca assimp, foi necessário instalar a biblioteca, alterar o arquivo "scene.cpp", modificando o método load() da classe scene,  que não foi muito complicado de encontrar exemplos na internet de como carregar malhas de triângulos para um código em c++ e modificar um pouco o makefile acrescentando algumas flags para compilar e linkar o código da biblioteca assimp;
Para randomizar as cores, precisei criar uma nova propriedade "cor" nas classes: intersection_record e na classe referente às primitivas, e alterar um pouco a função de intercesão de cada primitiva, guardando em intercection_record, o valor da cor da primitiva, para que a cor da primitiva influenciasse na cor final do pixel e no final do método load() da classe scene, fiz um pequeno loop para gerar valores randômicos de cor entre 0 e 255 usando o comando rand(), para implementação da câmera pinhole(descritos nos arquivos "perspective_camera.cpp" e "perspective_camera.h"), bastou um estudo dos slides da disciplina de Rendering Baseado em Física do professor Christian Pagot e aplicar os conceitos deste tipo de câmera para criar uma nova classe filha da classe câmera, mudando apenas um método, simplificando bastante meu trabalho ao criar os arquivos "perspective_camera.h" e "perspective_camera.cpp".

### Testes e análise de corretude do que foi requisitado na atividade 2 do RT-template

#### Teste com as 8 esferas

Para verificar a corretude do meu código, posicionei 8 esferas, como mostra os comandos do arquivo "scene.cpp", mostrados a seguir:

   "primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{ -0.5f, 0.5f, -1.0f }, 0.2f } ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{ -0.5f, -0.5f, -1.0f }, 0.2f } ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.5f,-0.5f, -1.0f }, 0.2f } ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.5f, 0.5f, -1.0f }, 0.2f } ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{ -0.5f, -0.5f, -2.0f }, 0.2f } ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{ -0.5f, 0.5f, -2.0f }, 0.2f } ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.5f,-0.5f, -2.0f }, 0.2f } ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.5f, 0.5f, -2.0f }, 0.2f } ) );"
    
Posicionei a câmera ortográfica em (0.0f,0.0f,1.0f), obtive o seguinte resultado:

![captura de tela de 2018-03-13 22-25-24](https://user-images.githubusercontent.com/30930332/37378323-7f369208-270d-11e8-9210-b80c0b4fd427.png)

Posicionando a mesma camera em (1.5f,0.0f,1.0f), sem modificar o vetor look at, obtive o seguinte resultado:

![captura de tela de 2018-03-13 22-44-12](https://user-images.githubusercontent.com/30930332/37378964-250c0bca-2710-11e8-9187-952cbda28162.png)

Posicionando a camera pinhole em (0.0f,0.0f,1.0f), obtive o seguinte resultado:

![captura de tela de 2018-03-13 22-49-19](https://user-images.githubusercontent.com/30930332/37379102-cfac5aa8-2710-11e8-8c76-68d3187d6cf2.png)

Posicionando a mesma camera em (0.3f,0.0f,1.0f), obtive o seguinte resultado:

![captura de tela de 2018-03-13 22-53-14](https://user-images.githubusercontent.com/30930332/37379244-71c39388-2711-11e8-9cc4-c986b11e293d.png)

Como o vetor look at da câmera permanece como sendo (0.0f,0.0f,-1.0f) nos quatro testes, concluo a corretude dos testes;

#### Teste com o MokeyHead do blender exportado em arquivo obj e lido com a biblioteca assimp

Com a camera ortográfica posicionada em (0.0f,0.0f,10.0f), o vetor look at em (0.0f,0.0f,-1.0f) e o arquivo "monkey2.obj" sendo acessado pela biblioteca assimp, modelado na posição (0,0,0)(lembrando que a diferença do "monkey.obj" para o "monkey2.obj" é uma simples rotação aplicada no eixo z(de 180 graus), para que a imagem do macaco não saísse de cabeça para baixo), obtive o seguinte resultado:

![captura de tela de 2018-03-13 23-09-00](https://user-images.githubusercontent.com/30930332/37379706-94746c3e-2713-11e8-8842-5fe2699e6058.png)

Caso faça a mesma coisa, mas utilizando a câmera pinhole, o resultado é este:

![captura de tela de 2018-03-13 23-11-24](https://user-images.githubusercontent.com/30930332/37379773-f2e0f206-2713-11e8-99cb-75582b4c1f9c.png)

## Terceira atividade

Na terceira atividade, foi implementado primeiramente a leitura da cor de cada objeto da cena do obj, utilizando a bilbioteca ASSIMP e lançando os primeiros raios por uma distribuição aleatória ao redor da área do pixel. O número de raios lançado por cada area de pixel é definido como uma entrada do teclado do usuário do executável do programa. O resultado desta primeira atualizaçao com uma cena simples(ainda sem passar o algoritmo para o path tracer,ou seja, ainda um ray tracer muito simples), encontra-se a seguir:

![captura de tela de 2018-05-05 12-53-31](https://user-images.githubusercontent.com/30930332/39665028-5f10fc96-5063-11e8-8d98-4e55daaba5fa.png)

Depois, na segunda parte, foi transformado o código que era um ray tracer em path tracer, que leva em consideração o número de raios secundários à colaborar com o valor final do pixel e o realismo do resultado final da imagem formada com o algoritmo do path tracer, conhecido pelo fotorrealismo(na primeira atividade, apenas os materiais perfeitamente difusos foram implementados). Os resultados encontram-se nas figuras a seguir:

12000 amostras e 10 raios secundários:

![captura de tela de 2018-05-05 12-59-09](https://user-images.githubusercontent.com/30930332/39665072-6885d02a-5064-11e8-810a-a326b7d89f49.png)

10000 amostras e 8 raios secundários:

![captura de tela de 2018-05-05 13-00-39](https://user-images.githubusercontent.com/30930332/39665077-905f6c96-5064-11e8-8a7a-d5dc86d2d980.png)

300 amostras e 8 raios secundários:

![captura de tela de 2018-05-05 12-59-38](https://user-images.githubusercontent.com/30930332/39665087-c821befe-5064-11e8-9554-f15f64b3408f.png)

## Quarta atividade

Na quarta atividade, o material tipo espelho foi implementado, resultados encontram-se a seguir:

1000 amostras e 10 raios secundários:

![captura de tela de 2018-05-05 12-59-58](https://user-images.githubusercontent.com/30930332/39665120-50e55e26-5065-11e8-986d-d9b9e87c34d2.png)

1000 amostras e 10 raios secundários:

![captura de tela de 2018-05-05 13-00-20](https://user-images.githubusercontent.com/30930332/39665112-434463c0-5065-11e8-90d0-cced94316739.png)

###OBS: Na atualização desse repositório para a terceira e quarta atividade descartaram os arquivos raytracer.cpp e raytracer.h e foram substituidos com as implementaçes do path tracer e seus respectivos arquivos .cpp e .h.

#include <iostream>
using namespace std;

struct NoArvore {
    int data;
    NoArvore* esquerda;
    NoArvore* direita;
};

int calcularProfundidade(NoArvore* raiz) {
    if (raiz == NULL) {
        return 0; 
    } else {
        
        int profundidadeEsquerda = calcularProfundidade(raiz->esquerda);
        int profundidadeDireita = calcularProfundidade(raiz->direita);

        
        return 1 + max(profundidadeEsquerda, profundidadeDireita);
    }
}

int main() {
    NoArvore *raiz = new NoArvore;
    raiz->data = 1;
    raiz->esquerda = NULL;
    raiz->direita = NULL;

    NoArvore* elementoEsquerda = new NoArvore;
    elementoEsquerda->data = 2;
    elementoEsquerda->esquerda = NULL;
    elementoEsquerda->direita = NULL;
    
    raiz->esquerda = elementoEsquerda;
    
    NoArvore* elementoDireita = new NoArvore;
    elementoDireita->data = 5;
    elementoDireita->esquerda = NULL;
    elementoDireita->direita = NULL;

    elementoEsquerda->direita = elementoDireita;
    
    NoArvore* elementoDireita2 = new NoArvore;
    elementoDireita2->data = 3;
    elementoDireita2->esquerda = NULL;
    elementoDireita2->direita = NULL;
    
    int profundidade = calcularProfundidade(raiz);
    
    cout << "Profundidade da arvore: " << profundidade << endl;

    return 0;
}


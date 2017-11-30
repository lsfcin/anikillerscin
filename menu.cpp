#include "menu.h"


Menu :: Menu(){

	this->mPrincipal = new PainelPrincipal();
	this->mHelp = new PainelHelp();
	this->mSingle = new PainelSingle();
	this->mMultiplayer = new PainelMultiplayer();
	this->mPlayer = new PainelPlayer();

	this->timerTeclado = new Timer(150);
	this->timerHelp = new Timer(500);
	this->ativo = true;
	this->comecarJogo = false;
	this->painelAtual = 0;
	this->nJogadores = 0;
	this->carroEscolhido = new int[4];
	this->corEscolhida = new int[4];
	for(int i = 0; i < 4; i++) {
		this->carroEscolhido[i] = Carro::CHEVETTE;
		this->corEscolhida[i] = Carro::PRETO;
	}
	
	/*this->carro =  new Chevette((new Ponto(3.95f, -4.02f, 8.45f)), new Vetor (1.f, 0.f, 0.f),
		new Vetor(0.0f, 1.0f, 0.0f), this->mSingle->getCor());*/
}

Menu :: ~Menu(){
	//PAINÉIS
	delete mPrincipal;
	delete mHelp;
	delete mSingle;
	delete mMultiplayer;
	delete mPlayer;

	//TIMERS
	delete timerTeclado;
	delete timerHelp;

//	delete carro;

}

void Menu :: draw(){	
	if(this->ativo){
		if(this->painelAtual == SINGLE_PLAYER)
			this->mSingle->draw();
		else if(this->painelAtual == PLAYER)
			this->mPlayer->draw();
	}
}

void Menu :: drawOrtho(){		
	if (this->ativo){
		switch(this->painelAtual){
			case PRINCIPAL:
				this->mPrincipal->drawOrtho();
				break;
			case SINGLE_PLAYER:
				this->mSingle->drawOrtho();
				break;
			case MULTIPLAYER:
				this->mMultiplayer->drawOrtho();
				break;
			case PLAYER:
				this->mPlayer->drawOrtho();
				break;
			case HELP:
				this->mHelp->drawOrtho();
				break;		
		}	
	}
}


void Menu :: update(){	
	if(this->ativo)
		this->tratarTeclado();	
}

void Menu :: tratarTeclado(){	
	if (this->painelAtual == PRINCIPAL)
		this->tratarTecladoPrincipal();
	else if (this->painelAtual == SINGLE_PLAYER) {
		this->nJogadores = 1;
		this->tratarTecladoSingle();	
	}
	else if (this->painelAtual == MULTIPLAYER) {
		//por hora o multiplayer soh serve pro versus e pra 2 jogadores
		this->nJogadores = 2;
		this->tratarTecladoMulti();
	} else if (this->painelAtual == PLAYER){
		this->tratarTecladoPlayer();
	} else if (this->painelAtual == HELP)
		this->tratarTecladoHelp();
	else if (this->painelAtual == EXIT)
		exit(1);		
}

void Menu :: tratarTecladoPrincipal(){
	static int escolhaAtual = SINGLE_PLAYER;		
		if (IsKeyPressed(UP)){
			if(this->timerTeclado->passouTempo()){
				if (escolhaAtual == SINGLE_PLAYER)
					escolhaAtual = EXIT;
				else
					escolhaAtual--;		
			}
		}
		else if (IsKeyPressed(DOWN)){
			if(this->timerTeclado->passouTempo()){
				if (escolhaAtual == EXIT)					
					escolhaAtual = SINGLE_PLAYER;
				else					
					escolhaAtual++;	
			}
		}else if (IsKeyPressed(ENTER)){
			if(this->timerTeclado->passouTempo()){
				this->painelAtual = escolhaAtual;
				if(escolhaAtual == HELP)
					this->timerHelp->zerar();
				else if(escolhaAtual == EXIT) {
					exit(1);
				}
			}
		}else if (IsKeyPressed(ESCAPE) && this->timerTeclado->passouTempo() )
			exit(1);

	this->mPrincipal->setEscolha(escolhaAtual);
}

void Menu :: tratarTecladoSingle(){
	static int escolha = START;
	if (IsKeyPressed(UP)){
		if(this->timerTeclado->passouTempo()){
			if(escolha == START)
				escolha = SETA_DIREITA;
			else if(escolha == BACK)
				escolha = SETA_ESQUERDA;
			else {
				escolha = SETA_UP;
				this->corEscolhida[0] = (++corEscolhida[0]) % Carro::NUM_CORES;
			}
		}
	}
	else if (IsKeyPressed(DOWN)){
		if(this->timerTeclado->passouTempo()){
			if (escolha == SETA_ESQUERDA)
				escolha = BACK;
			else if (escolha == SETA_DIREITA)
				escolha = START;						
			else if(escolha == SETA_UP)
				escolha = SETA_DIREITA;
		}
	}
	else if (IsKeyPressed(RIGHT)){
		if(this->timerTeclado->passouTempo()){
			if (escolha == BACK)
				escolha = START;
			else if (escolha == SETA_ESQUERDA) {
				escolha = SETA_DIREITA;
				this->carroEscolhido[0] = (++this->carroEscolhido[0]) % Carro::NUM_CARROS;
			} else if (escolha == SETA_DIREITA)
				this->carroEscolhido[0] = (++this->carroEscolhido[0]) % Carro::NUM_CARROS;
			else if (escolha == SETA_UP) {
				escolha = SETA_DIREITA;
				this->carroEscolhido[0] = (++this->carroEscolhido[0]) % Carro::NUM_CARROS;
			}

		}
	}else if (IsKeyPressed(LEFT)){
		if(this->timerTeclado->passouTempo()){
			if (escolha == START)
				escolha = BACK;
			else if (escolha == SETA_DIREITA) {
				escolha = SETA_ESQUERDA;
				this->carroEscolhido[0] = (--this->carroEscolhido[0]) % Carro::NUM_CARROS;
			}
			else if (escolha == SETA_ESQUERDA)
				this->carroEscolhido[0] = (--this->carroEscolhido[0]) % Carro::NUM_CARROS;
			else if (escolha == SETA_UP) {
				escolha = SETA_ESQUERDA;
				this->carroEscolhido[0] = (--this->carroEscolhido[0]) % Carro::NUM_CARROS;
			}
		}
	}else if (IsKeyPressed(ENTER)){
		if(this->timerTeclado->passouTempo()){
			if(escolha == BACK)
				this->painelAtual = PRINCIPAL;			
			else{	
				this->ativo = false;				
				this->comecarJogo = true;
				this->painelAtual = PRINCIPAL;	
				escolha = START;
			}
			this->mSingle->zerarAnguloRotacao();
		}
	}else if (IsKeyPressed(ESCAPE) && this->timerTeclado->passouTempo()){
		this->painelAtual = PRINCIPAL;
		this->mSingle->zerarAnguloRotacao();
	}

	this->mSingle->setEscolha(escolha);
	this->mSingle->setCarroEscolhido(this->carroEscolhido[0]);
	this->mSingle->setCor(this->corEscolhida[0]);
}

void Menu :: tratarTecladoMulti(){
	static int escolhaAtual = VERSUS;	
		if (IsKeyPressed(UP)){
			if(this->timerTeclado->passouTempo()){
				if (escolhaAtual == VERSUS)
					escolhaAtual = BACK;
				else
					escolhaAtual--;		
			}
		}
		else if (IsKeyPressed(DOWN)){
			if(this->timerTeclado->passouTempo()){
				if (escolhaAtual == BACK)					
					escolhaAtual = VERSUS;
				else					
					escolhaAtual++;	
			}
		}else if (IsKeyPressed(ENTER)){
			if(this->timerTeclado->passouTempo()){
				this->painelAtual = escolhaAtual;
				if(escolhaAtual == VERSUS){
					this->painelAtual = PLAYER;
				}
				else if(escolhaAtual == BACK)
					this->painelAtual = PRINCIPAL;
				escolhaAtual = VERSUS; 
			}
		}else if (IsKeyPressed(ESCAPE) && this->timerTeclado->passouTempo() ){
			this->painelAtual = PRINCIPAL;
			escolhaAtual = VERSUS;
		}
		this->mMultiplayer->setEscolha(escolhaAtual);
}

void Menu :: tratarTecladoPlayer() {
	//inteiro pra indicar o jogador do versus que está escolhendo o carro no momento
	static int jogadorAtual = 0;
	static int escolha = OK;
	if (IsKeyPressed(UP)){
		if(this->timerTeclado->passouTempo()){
			escolha = SETA_UP;
			this->corEscolhida[jogadorAtual] = (++corEscolhida[jogadorAtual]) % Carro::NUM_CORES;			
		}
	}
	else if (IsKeyPressed(DOWN)){
		if(this->timerTeclado->passouTempo()){
			escolha = OK;
		}
	}
	else if (IsKeyPressed(RIGHT)){
		if(this->timerTeclado->passouTempo()){
			escolha = SETA_DIREITA;
			this->carroEscolhido[jogadorAtual] = (++this->carroEscolhido[jogadorAtual]) % Carro::NUM_CARROS;			
		}
	}else if (IsKeyPressed(LEFT)){
		if(this->timerTeclado->passouTempo()){
			escolha = SETA_ESQUERDA;
			this->carroEscolhido[jogadorAtual] = (--this->carroEscolhido[jogadorAtual]) % Carro::NUM_CARROS;
		}
	}else if (IsKeyPressed(ENTER)){
		if(this->timerTeclado->passouTempo()){
			if(escolha == OK) {
				if(jogadorAtual == this->nJogadores - 1) {
					this->ativo = false;				
					this->comecarJogo = true;
					this->painelAtual = PRINCIPAL;	
					escolha = BACK;
					jogadorAtual = 0;
				} else {
					jogadorAtual++;
				}
				this->mSingle->zerarAnguloRotacao();
			}
		}
	}

	this->mPlayer->setEscolha(escolha);
	this->mPlayer->setCarroEscolhido(this->carroEscolhido[jogadorAtual]);
	this->mPlayer->setCor(this->corEscolhida[jogadorAtual]);
}
void Menu :: tratarTecladoHelp(){	
	if (IsKeyPressed(ESCAPE) || IsKeyPressed(ENTER)){
		if(this->timerHelp->passouTempo() && this->timerTeclado->passouTempo()){
			this->painelAtual = PRINCIPAL; 			
		}
	}
}

void Menu :: ativar(bool ativar){
	this->ativo = ativar;
	this->timerTeclado->zerar();
}

bool Menu :: ativado(){
	return this->ativo;
}

bool Menu :: podeComecarJogo(){
	bool retorno = this->comecarJogo;
	this->comecarJogo = false;
	return retorno;	
}
int* Menu :: getCorEscolhida(){
	return this->corEscolhida;
}

int* Menu :: getCarroEscolhido(){
	return this->carroEscolhido;	
}

int  Menu :: getNJogadores() {
	return this->nJogadores;
}

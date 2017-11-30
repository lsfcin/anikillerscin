#include "jogo.h"

Jogo::Jogo() {
	
	
	this->mundoAtual = 1;
	this->menu = new Menu();

//	this->mundoAtivo = true;
	this->painelEscapeAtivo = false;
	this->painelHelpAtivo = false;
	this->painelWinnerAtivo = false;
	this->destruirMundo = false;
	this->timerTeclado = new Timer(150);
	this->timerEscape = new Timer(500);
	this->pEscape = new PainelEscape();
	this->pHelp = new PainelHelp();
	this->pWinLose = new PainelWinLose();
	
	for(int i = 0; i < 4 ; i++)
		this->jogadores[i] = 0; 
	

	this->nJogadores = 0;
	this->vencedor = 0;
	this->world = 0;
}

Jogo::~Jogo() {
	delete menu;
	if(this->world != 0)
		delete this->world;

	for(int i = 0; i < 4 ; i++)
		if(this->jogadores[i] != 0)
			delete this->jogadores[i];
		
	

	delete timerTeclado;
	delete timerEscape;
	delete pEscape;
	delete pHelp;
}

bool Jogo::acabouJogo() {
	bool retorno = false;
	if(this->nJogadores == 1 || this->nJogadores == 2 ){
		if((this->jogadores[0]->life <= 0)){
			if(this->jogadores[1]->life > 0)
				this->vencedor = 2;
			else
				this->vencedor = 0;
			retorno = true;
		}else if(this->jogadores[1]->life <= 0){
			this->vencedor = 1;
			retorno = true;
		}
	}else if (this->nJogadores == 3){
		// TODO
	}else if(this->nJogadores == 4){
		// TODO
	}
	return retorno;
}
void Jogo::comecarJogo() {
	this->nJogadores = this->menu->getNJogadores();
	
	int *tempCarro = this->menu->getCarroEscolhido();
	int *tempCor = this->menu->getCorEscolhida();
	int *carroEscolhido = new int[this->nJogadores];
	int *corEscolhida = new int[this->nJogadores];
	for(int i = 0; i < this->nJogadores; i++){		
		carroEscolhido[i] = tempCarro[i];
		corEscolhida[i] = tempCor[i];
	}
	tempCarro = tempCor = 0;
	Ponto *ponto[2];
	Vetor *n[2];
	ponto[0] = new Ponto(13.95f, -4.02f, 8.45f);
	ponto[1] = new Ponto(13.95f, -4.02f, 3.45f);		
	n[0] = new Vetor(0.f, 0.0f, 1.0);
	n[1] = new Vetor(0.f, 0.0f, -1.0);

	//DELETARRRRR
	//colocar inimigo com IA
	this->jogadores[1] = new Jogador(new Diablo(ponto[1],n[1], new Vetor(0.f, 1.0f, 0.0),1), this->nJogadores, 2);

	for(int i = 0; i < this->nJogadores; i++){
		Carro *carro;
		int cor = corEscolhida[i];		
		switch(carroEscolhido[i]){
			case Carro::CHEVETTE:
				carro = new Chevette(ponto[i],n[i], new Vetor(0.f, 1.0f, 0.0),cor);
				break;
			case Carro::CHEVETTE_ESCOLIOSE:
				carro = new ChevetteEscoliose(ponto[i], n[i], new Vetor(0.f, 1.0f, 0.0),cor);
				break;
			case Carro::PICAPE:
				carro = new Picape(ponto[i], n[i], new Vetor(0.f, 1.0f, 0.0),cor);
				break;
			case Carro::CORNOCAR:
				carro = new CornoCar(ponto[i], n[i], new Vetor(0.f, 1.0f, 0.0),cor);
				break;
			case Carro::DIABLO:
				carro = new Diablo(ponto[i], n[i], new Vetor(0.f, 1.0f, 0.0),cor);
				break;
			default:				
				carro = new Chevette(ponto[i], n[i], new Vetor(0.f, 1.0f, 0.0),cor);
				break;
		}
		this->jogadores[i] = new Jogador(carro, this->nJogadores, i+1);
	}

	//DELETARRRRRR, ou n....
	for(int i = 0;i < 10;i++){
			this->jogadores[0]->carro->armas->mT[i]->perseguir(this->jogadores[1]->carro->centro);
			this->jogadores[1]->carro->armas->mT[i]->perseguir(this->jogadores[0]->carro->centro);
	}

	delete [] carroEscolhido;
	delete [] corEscolhida;
}
void Jogo::update() {
	this->menu->update();

	// Caso apertei START no Menu
	if(this->menu->podeComecarJogo()) {
		comecarJogo();		

		this->world = new Mundo(this->mundoAtual);
	}
	//SE O MUNDO EXISTE
	if(this->world != 0){
		this->tratarTeclado();
		
		if(this->jogadores[0]->life > 0 && this->jogadores[1]->life > 0){
			if(this->jogadores[0]->carro->colidiu(*this->jogadores[1]->carro)){
				this->jogadores[0]->carro->tratarColisaoCarro(*this->jogadores[1]->carro);
				this->jogadores[0]->life -= 1;
				this->jogadores[1]->life -= 1;
			}

			this->colisaoMinas();
			this->colisaoObstaculos();
			this->colisaoMT();
			this->colisaoObstaculoMT();
			this->colisaoMetralhadora();
			this->colisaoObstaculoMetralhadora();
		}

		//CASO EU SAÍ DO JOGO E VOLTEI PRO MENU
		if(this->destruirMundo){
			delete this->world;			
			this->world = 0;
			this->destruirMundo = false;
			this->painelEscapeAtivo = false;
			this->painelHelpAtivo = false;
			this->painelWinnerAtivo = false;
			this->mundoAtual = 1;	
			for(int i = 0; i < this->nJogadores; i++)
				delete this->jogadores[i];

			this->menu->ativar(true);
		}		
	}
}

void Jogo::draw() {
	glColor3f(1.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	this->menu->draw();
	if(this->world != 0){
		for (int posicaoAtual = 1; posicaoAtual <= this->nJogadores; posicaoAtual++){	
			if (this->nJogadores == 1){
				glViewport (0, 0, WIDTH, HEIGHT);																									
				this->jogadores[0]->camera->fotografar();
			}else if (this->nJogadores == 2){
				if(posicaoAtual == 1){
					glViewport (0, HEIGHT/2, WIDTH, HEIGHT/2);										
					this->jogadores[0]->camera->fotografar();
				}else{
					glViewport (0, 0, WIDTH, HEIGHT/2);										
					this->jogadores[1]->camera->fotografar();
				}					
			}		
				this->world->draw();
				
				//REPENSAR...
				//criar classe jogador com IA...
				this->jogadores[1]->draw();
				for(int i = 0; i < this->nJogadores ; i++ )
					this->jogadores[i]->draw();		
		}
	}
}

void Jogo::drawOrtho() {
	this->menu->drawOrtho();
	if(this->world != 0){
		glViewport (0, 0, WIDTH, HEIGHT);


		if(this->painelEscapeAtivo){
			this->pEscape->drawOrtho();
		}else if(this->painelHelpAtivo)
			this->pHelp->drawOrtho();
		else if(this->painelWinnerAtivo){
			this->pWinLose->drawOrtho();
		}
	
		this->jogadores[0]->drawOrtho();
		this->jogadores[1]->drawOrtho();
	}
}

void Jogo::tratarTeclado() {
	static int escolha = 1;
	static int opcao = 0;
	if(this->painelEscapeAtivo){
		if (IsKeyPressed(UP)){
			if(this->timerTeclado->passouTempo()){
				if(escolha == 1)
					escolha = 3;
				else
					escolha--;		
			}
		}
		if (IsKeyPressed(DOWN)){
			if(this->timerTeclado->passouTempo()){
				if(escolha == 3){
					escolha = 1;
				}else{
					escolha++;
				}
			}
		}
		if (IsKeyPressed(ENTER) && this->timerTeclado->passouTempo()){
			if(this->timerEscape->passouTempo() && escolha == 1){
				this->painelEscapeAtivo = false;				
			}else if(escolha == 2){				
				this->painelEscapeAtivo = false;
				this->painelHelpAtivo = true;
			}else if(escolha == 3){				
				this->painelEscapeAtivo = false;
				this->destruirMundo = true;
			}
		}else if (IsKeyPressed(ESCAPE) && this->timerTeclado->passouTempo() && this->timerEscape->passouTempo()){
			this->painelEscapeAtivo = false;			
		}
		this->pEscape->setEscolha(escolha);

	}else if(this->painelHelpAtivo){
		if(IsKeyPressed(ENTER) && this->timerTeclado->passouTempo()){
			this->painelEscapeAtivo = true;
			this->painelHelpAtivo = false;
		}else if(IsKeyPressed(ESCAPE) && this->timerTeclado->passouTempo()){
			this->painelEscapeAtivo = true;
			this->painelHelpAtivo = false;		
		}			
	}else if(this->painelWinnerAtivo){
		this->tratarTecladoWinLose();
		/*
		if ((IsKeyPressed(UP) || IsKeyPressed(DOWN)) && this->timerTeclado->passouTempo()){			
			opcao = (opcao + 1 )%2; 
		}if (IsKeyPressed(ENTER)){
			if(opcao == 0){				
				this->iniciarFase();				
			}			
			else{
				this->destruirMundo = true;
			}
				
			this->painelWinnerAtivo = false;	
		}*/
	}else{
		if(IsKeyPressed(ESCAPE) && this->timerEscape->passouTempo() )
			this->painelEscapeAtivo= true;			
		else if(!acabouJogo()){
			this->jogadores[0]->update(IsKeyPressed('w'),IsKeyPressed('s'), IsKeyPressed('a'), IsKeyPressed('d'), IsKeyPressed('1'), IsKeyPressed('2'), IsKeyPressed('3'));	
			this->jogadores[1]->update(IsKeyPressed('i'),IsKeyPressed('k'), IsKeyPressed('j'), IsKeyPressed('l'), IsKeyPressed('9'), IsKeyPressed('0'), IsKeyPressed('8'));

			this->jogadores[0]->camera->update(this->jogadores[0]->carro);
			this->jogadores[1]->camera->update(this->jogadores[1]->carro);
		}else{
			this->pWinLose->setNJogadores(this->nJogadores);
			this->pWinLose->setVencedor(this->vencedor);
			this->painelWinnerAtivo = true;
		}
	}
}

void Jogo::iniciarFase() {
	this->mundoAtual = (this->mundoAtual++)%2;
	this->world = new Mundo(this->mundoAtual);
	this->comecarJogo();
}

void Jogo::colisaoMinas(){

	for(int i = 0;i < 3;i++){
		if(this->jogadores[0]->carro->armas->mina[i]->atirada){

				if(this->jogadores[0]->carro->colidiu(*this->jogadores[0]->carro->armas->mina[i])){
					this->jogadores[0]->carro->armas->mina[i]->atirada = false;
					this->jogadores[0]->life -= 10;
					
				}

				if(this->jogadores[1]->carro->colidiu(*this->jogadores[0]->carro->armas->mina[i])){
					this->jogadores[0]->carro->armas->mina[i]->atirada = false;
					this->jogadores[1]->life -= 10;
					
				}
		}

		if(this->jogadores[1]->carro->armas->mina[i]->atirada){

				if(this->jogadores[0]->carro->colidiu(*this->jogadores[1]->carro->armas->mina[i])){
					this->jogadores[1]->carro->armas->mina[i]->atirada = false;
					this->jogadores[0]->life -= 10;
				}

				if(this->jogadores[1]->carro->colidiu(*this->jogadores[1]->carro->armas->mina[i])){
					this->jogadores[1]->carro->armas->mina[i]->atirada = false;
					this->jogadores[1]->life -= 10;
				}
		}

	}
}

void Jogo::colisaoObstaculos(){
	for(int i = 0;i < 50;i++){
		if(this->world->obstaculos[i] != NULL){
			if(this->jogadores[0]->carro->colidiu(*this->world->obstaculos[i]))
				this->jogadores[0]->carro->tratarColisaoObstaculo(*this->world->obstaculos[i]);
		
			if(this->jogadores[1]->carro->colidiu(*this->world->obstaculos[i]))
				this->jogadores[1]->carro->tratarColisaoObstaculo(*this->world->obstaculos[i]);
		}
	}
}
void Jogo::colisaoMetralhadora(){
	for(int i = 0;i < 50;i++){
		if(this->jogadores[0]->carro->armas->metralhadora[i]->atirada){

				if(this->jogadores[1]->carro->colidiu(*this->jogadores[0]->carro->armas->metralhadora[i])){
					this->jogadores[0]->carro->armas->metralhadora[i]->atirada = false;
					this->jogadores[1]->life -= 5;
					
				}
		}

		if(this->jogadores[1]->carro->armas->metralhadora[i]->atirada){

				if(this->jogadores[0]->carro->colidiu(*this->jogadores[1]->carro->armas->metralhadora[i])){
					this->jogadores[1]->carro->armas->metralhadora[i]->atirada = false;
					this->jogadores[0]->life -= 5;
				}
		}

	}
}
void Jogo::colisaoObstaculoMetralhadora(){
	for(int i = 0;i < 50;i++){
		if(this->world->obstaculos[i] != NULL){
			for(int j = 0; j < 50;j++){
				if(this->jogadores[0]->carro->armas->metralhadora[j]->atirada){
					if(this->jogadores[0]->carro->armas->metralhadora[j]->colidiu(*this->world->obstaculos[i])){
						this->jogadores[0]->carro->armas->metralhadora[j]->atirada = false;
					}
				}
			}
			for(int j = 0; j < 50;j++){
				if(this->jogadores[1]->carro->armas->metralhadora[j]->atirada){
					if(this->jogadores[1]->carro->armas->metralhadora[j]->colidiu(*this->world->obstaculos[i])){
						this->jogadores[1]->carro->armas->metralhadora[j]->atirada = false;
					}
				}
			}

		}
	}
}


void Jogo::colisaoObstaculoMT(){
	for(int i = 0;i < 50;i++){
		if(this->world->obstaculos[i] != NULL){
			for(int j = 0; j < 10;j++){
				if(this->jogadores[0]->carro->armas->mT[j]->atirada){
					if(this->jogadores[0]->carro->armas->mT[j]->colidiu(*this->world->obstaculos[i])){
						this->jogadores[0]->carro->armas->mT[j]->atirada = false;
					}
				}
			}
			for(int j = 0; j < 10;j++){
				if(this->jogadores[1]->carro->armas->mT[j]->atirada){
					if(this->jogadores[1]->carro->armas->mT[j]->colidiu(*this->world->obstaculos[i])){
						this->jogadores[1]->carro->armas->mT[j]->atirada = false;
					}
				}
			}

		}
	}
}

void Jogo::colisaoMT(){
	for(int i = 0;i < 10;i++){
		if(this->jogadores[0]->carro->armas->mT[i]->atirada){

				if(this->jogadores[1]->carro->colidiu(*this->jogadores[0]->carro->armas->mT[i])){
					this->jogadores[0]->carro->armas->mT[i]->atirada = false;
					this->jogadores[1]->life -= 20;
					
				}
		}

		if(this->jogadores[1]->carro->armas->mT[i]->atirada){

				if(this->jogadores[0]->carro->colidiu(*this->jogadores[1]->carro->armas->mT[i])){
					this->jogadores[1]->carro->armas->mT[i]->atirada = false;
					this->jogadores[0]->life -= 20;
				}
		}

		if(this->jogadores[0]->carro->armas->mT[i]->atirada){

				if(this->jogadores[0]->carro->colidiu(*this->jogadores[0]->carro->armas->mT[i])){
					this->jogadores[0]->carro->armas->mT[i]->atirada = false;
					this->jogadores[0]->life -= 20;
					
				}
		}

		if(this->jogadores[1]->carro->armas->mT[i]->atirada){

				if(this->jogadores[1]->carro->colidiu(*this->jogadores[1]->carro->armas->mT[i])){
					this->jogadores[1]->carro->armas->mT[i]->atirada = false;
					this->jogadores[1]->life -= 20;
				}
		}

	}
}

void Jogo::tratarTecladoWinLose(){
static int escolha = 0;
	if ((IsKeyPressed(UP) || IsKeyPressed(DOWN)) && this->timerTeclado->passouTempo())
		escolha = (escolha + 1 )%2; 

	if (IsKeyPressed(ENTER)){
		if(escolha == 0)				
			this->iniciarFase();									
		else
			this->destruirMundo = true;

		this->painelWinnerAtivo = false;	
	}
	this->pWinLose->setEscolha(escolha);
}

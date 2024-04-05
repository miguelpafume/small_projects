#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
	// Inicializando GLFW
	glfwInit();

	// Tamanho da janela
	size_t window_width{ 1280 };
	size_t window_height{ 720 };

	// Dita para o GLFW qual versão do OpenGL estou usando, nesse caso é a 4.6 (mais recente)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	// Dita para o GLFW quão "perfil" estamos usando
	// Nesse caso é o CORE, que inclui apenas funções modernas
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Cria a janela usando o tamanho declarado no em width e height
	GLFWwindow* Window { glfwCreateWindow(window_width, window_height, "ANDREY VIADAO KKKKKKKKKKKK", NULL, NULL) };

	// Verifica se a janela realmente foi criada
	if (Window == NULL) {
		std::cout << "Erro ao tentar criar a janela." << std::endl; 
		glfwTerminate();
		return -1;
	}

	// Mostra a janela para o contexto do glfw
	glfwMakeContextCurrent(Window);

	// Inicia o glad 
	gladLoadGL();
	// Configura a área da janela que o glad funcionará
	glViewport(0, 0, window_width, window_height);

	// Coloca a cor laranja no background
	glClearColor(0.9f, 0.6f, 0.0f, 1.0f);
	// Limpa o buffer e aloca a nova cor a ele
	glClear(GL_COLOR_BUFFER_BIT);
	// Troca o back buffer (a cor logo acima) com o front buffer (o que está sendo mostrado na tela, neste caso nada)
	glfwSwapBuffers(Window);

	// Enquanto o comando de fechar a janela não for enviado, manter ela sendo atualizada
	while (!glfwWindowShouldClose(Window)) {
		// Mantem todos os eventos do glfw
		glfwPollEvents();
	}

	// Destroi a janela
	glfwDestroyWindow(Window);
	// Termina o glfw
	glfwTerminate();
	return 0;
}
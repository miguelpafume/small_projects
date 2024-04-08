#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Atualiza o opengl com a área que está sendo usada
void FrameBufferSizeCallback(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
}

// Processa qualquer input, neste caso apenas o ESC fecha o programa
void ProcessInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

// Largura e altura da tela por padrão
const unsigned int WINDOW_WIDTH{ 1280 };
const unsigned int WINDOW_HEIGHT{ 720 };

int main() {
	// Inicializando GLFW
	glfwInit();

	// Dita para o GLFW qual versão do OpenGL estou usando, nesse caso é a 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Dita para o GLFW quão "perfil" estamos usando
	// Nesse caso é o CORE, que inclui apenas funções modernas
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Cria a janela usando o tamanho declarado no em width e height
	GLFWwindow *window{glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "ANDREY VIADAO KKKKKKKKKKKK", NULL, NULL)};

	// Verifica se a janela realmente foi criada
	if (window == NULL) {
		std::cout << "Erro ao tentar criar a janela." << std::endl; 
		glfwTerminate();
		return -1;
	}

	// Mostra a janela para o contexto do glfw
	glfwMakeContextCurrent(window);
	// Inicia o glad 
	gladLoadGL();
	// Configura a área da janela que o glad funcionará, e faz o resize necessário
	glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallback);

	GLfloat vertices[] {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	GLuint vertex_buffer {};
	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Enquanto o comando de fechar a janela não for enviado, manter ela sendo atualizada
	while (!glfwWindowShouldClose(window)) {
		ProcessInput(window);

		// Coloca a cor laranja no background
		glClearColor(0.9f, 0.6f, 0.0f, 1.0f);
		// Limpa o buffer e aloca a nova cor a ele
		glClear(GL_COLOR_BUFFER_BIT);
		// Troca o back buffer (a cor logo acima) com o front buffer (o que está sendo mostrado na tela, neste caso nada)
		glfwSwapBuffers(window);


		// Mantem todos os eventos do glfw
		glfwPollEvents();
	}

	// Destroi a janela
	glfwDestroyWindow(window);
	// Termina o glfw
	glfwTerminate();
	return 0;
}
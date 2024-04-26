#include "Map.hpp"
//il faut transformer std::vector<std::vector<std::string> > en std::vector<std::vector<char> >


void initializeOpenGL() {
    if (!glfwInit()) {
        std::cerr << "Échec de l'initialisation de GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Map", NULL, NULL);
    if (!window) {
        std::cerr << "Échec de la création de la fenêtre" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
}

void drawMap(const std::vector<std::vector<std::string>>& map) {
    for (size_t row = 0; row < map.size(); ++row) {
        for (size_t col = 0; col < map[row].size(); ++col) {
            const char & element = static_cast<char>(map[row][col]);
            
            // Vérifiez l'élément pour décider de ce qu'il faut dessiner
            if (element == "X") {
                // Dessinez un carré ou un rectangle spécifique pour la cellule "X"
                float x = col * TILE_SIZE;
                float y = row * TILE_SIZE;

                glBegin(GL_QUADS);
                glVertex2f(x, y);
                glVertex2f(x + TILE_SIZE, y);
                glVertex2f(x + TILE_SIZE, y + TILE_SIZE);
                glVertex2f(x, y + TILE_SIZE);
                glEnd();
            }
        }
    }
}

void mainLoop(GLFWwindow* window, const std::vector<std::vector<std::string>>& map) {
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawMap(map);

        // Gestion des entrées utilisateur (par exemple, clavier, souris)
        // Vous pouvez ajouter ici le code de gestion des entrées de l'utilisateur
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}

int main(int argc, char **argv) {
    if (argc != 2)
    {
        std::cerr << "only one arg" << std::endl;
        return 1;
    }
    std::ifstream inputFile (argv[1]);
    if (!inputFile.is_open())
    {
        std::cerr << "ERROR: " << argv[1] << " can't open !" << std::endl;
        return 1; 
    }
    try
    {
        Map map;
        std::string line;
        while(std::getline(inputFile, line))
        {
            map.setMap(line);
        }
        map.parsMap();

        initializeOpenGL();
        GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Map", NULL, NULL);
        if (!window) {
            std::cerr << "Échec de la création de la fenêtre" << std::endl;
            glfwTerminate();
            return EXIT_FAILURE;
        }
        //drawMap(map.getMap());
        mainLoop(window, map.getMap());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    inputFile.close();
    return 0;
}
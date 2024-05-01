#include "Map_parsing.hpp"
#include "Map.hpp"


void initializeOpenGL() {
    if (!glfwInit()) {
        std::cerr << "Échec de l'initialisation de GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }
}

float calculateTileSize(const std::vector<std::vector<Node>>& map, int windowWidth, int windowHeight) {
    size_t numRows = map.size();
    size_t numCols = map[0].size();
    
    float tileWidth = static_cast<float>(windowWidth) / numCols;
    float tileHeight = static_cast<float>(windowHeight) / numRows;
    
    return std::min(tileWidth, tileHeight);
}

void drawMap(const std::vector<std::vector<Node>>& map, float TILE_SIZE) {
    for (size_t row = 0; row < map.size(); ++row) {
        for (size_t col = 0; col < map[row].size(); ++col) {
            if (map[row][col].getNode() == '1') {
                glColor3f(1.0f, 0.0f, 0.0f);
            } 
            else if (map[row][col].getNode() == '0') {
                glColor3f(1.0f, 1.0f, 1.0f);
            }
            else
                glColor3f(0.0f, 1.0f, 0.0f);
            
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

void mainLoop(GLFWwindow* window, Map map) {
    float TILE_SIZE = calculateTileSize(map.getMap(), WIDTH, HEIGHT);
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawMap(map.getMap(), TILE_SIZE);
        map.generation();
        map.update();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}

void setupViewport() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, WIDTH, HEIGHT, 0.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv) {
    Map map;
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
        MapParsing map_parse;
        std::string line;
        while(std::getline(inputFile, line))
        {
            map_parse.setMapParsing(line);
        }
        map_parse.parsMapParsing();
        map.setMap(map_parse.getMapParsing());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    initializeOpenGL();
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Map", NULL, NULL);
    if (!window) {
        std::cerr << "Échec de la création de la fenêtre" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);
    setupViewport();
    mainLoop(window, map);
    inputFile.close();
    return 0;
}
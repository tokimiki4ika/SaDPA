#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

void FirstExp(int pre_size, double length, sf::RenderWindow &window, double &x,
              double &y);
void SecondExp(int pre_size, double length, sf::RenderWindow &window, double &x,
               double &y);
void ThirdExp(int pre_size, double length, sf::RenderWindow &window, double &x,
              double &y);
void FourthExp(int pre_size, double length, sf::RenderWindow &window, double &x,
               double &y);
void DrawLine(double xPos, double yPos, sf::RenderWindow &window, double &x,
              double &y);

void FirstExp(int pre_size, double length, sf::RenderWindow &window, double &x,
              double &y) {
  if (pre_size > 0) {
    FourthExp(pre_size - 1, length, window, x, y);
    DrawLine(length, 0, window, x, y);
    FirstExp(pre_size - 1, length, window, x, y);
    DrawLine(0, length, window, x, y);
    FirstExp(pre_size - 1, length, window, x, y);
    DrawLine(-length, 0, window, x, y);
    ThirdExp(pre_size - 1, length, window, x, y);
  }
}

void SecondExp(int pre_size, double length, sf::RenderWindow &window, double &x,
               double &y) {
  if (pre_size > 0) {
    ThirdExp(pre_size - 1, length, window, x, y);
    DrawLine(-length, 0, window, x, y);
    SecondExp(pre_size - 1, length, window, x, y);
    DrawLine(0, -length, window, x, y);
    SecondExp(pre_size - 1, length, window, x, y);
    DrawLine(length, 0, window, x, y);
    FourthExp(pre_size - 1, length, window, x, y);
  }
}

void ThirdExp(int pre_size, double length, sf::RenderWindow &window, double &x,
              double &y) {
  if (pre_size > 0) {
    SecondExp(pre_size - 1, length, window, x, y);
    DrawLine(0, -length, window, x, y);
    ThirdExp(pre_size - 1, length, window, x, y);
    DrawLine(-length, 0, window, x, y);
    ThirdExp(pre_size - 1, length, window, x, y);
    DrawLine(0, length, window, x, y);
    FirstExp(pre_size - 1, length, window, x, y);
  }
}

void FourthExp(int pre_size, double length, sf::RenderWindow &window, double &x,
               double &y) {
  if (pre_size > 0) {
    FirstExp(pre_size - 1, length, window, x, y);
    DrawLine(0, length, window, x, y);
    FourthExp(pre_size - 1, length, window, x, y);
    DrawLine(length, 0, window, x, y);
    FourthExp(pre_size - 1, length, window, x, y);
    DrawLine(0, -length, window, x, y);
    SecondExp(pre_size - 1, length, window, x, y);
  }
}

void DrawLine(double xPos, double yPos, sf::RenderWindow &window, double &x,
              double &y) {
  sf::Vertex Line[] = {
      sf::Vertex(sf::Vector2f((int)x, (int)y)),
      sf::Vertex(sf::Vector2f((int)(x + xPos), (int)(y + yPos)))};
  window.draw(Line, 2, sf::Lines);
  x += xPos;
  y += yPos;
}

int main() {
  int window_size = 960;
  int size_curve;

  double x = 25, y = 25;

  do {
    std::cout << "Введите размер кривой Гильберта(1 - 10): ";
    std::cin >> size_curve;
  } while (size_curve < 1 || size_curve > 10);

  double length_line = (window_size - 50) / (pow(2, size_curve) - 1.);
  if (length_line < 0.2) {
    throw std::logic_error(
        "Размер кривой Гильберта не помещается в размер окна");
  }

  sf::RenderWindow Window(sf::VideoMode(window_size, window_size),
                          "Hilbert Curve");

  FirstExp(size_curve, length_line, Window, x, y);

  Window.display();

  while (Window.isOpen()) {
    sf::Event event;
    while (Window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        Window.close();
      }
    }
  }

  return 0;
}

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

void DrawCurveRight(int pre_size, double length, sf::RenderWindow &window, double &x,
              double &y);
void DrawCurveLeft(int pre_size, double length, sf::RenderWindow &window, double &x,
               double &y);
void DrawCurveUp(int pre_size, double length, sf::RenderWindow &window, double &x,
              double &y);
void DrawCurveDown(int pre_size, double length, sf::RenderWindow &window, double &x,
               double &y);
void DrawLine(double xPos, double yPos, sf::RenderWindow &window, double &x,
              double &y);

void DrawCurveRight(int pre_size, double length, sf::RenderWindow &window, double &x,
              double &y) {
  if (pre_size > 0) {
    DrawCurveDown(pre_size - 1, length, window, x, y);
    DrawLine(length, 0, window, x, y);
    DrawCurveRight(pre_size - 1, length, window, x, y);
    DrawLine(0, length, window, x, y);
    DrawCurveRight(pre_size - 1, length, window, x, y);
    DrawLine(-length, 0, window, x, y);
    DrawCurveUp(pre_size - 1, length, window, x, y);
  }
}

void DrawCurveLeft(int pre_size, double length, sf::RenderWindow &window, double &x,
               double &y) {
  if (pre_size > 0) {
    DrawCurveUp(pre_size - 1, length, window, x, y);
    DrawLine(-length, 0, window, x, y);
    DrawCurveLeft(pre_size - 1, length, window, x, y);
    DrawLine(0, -length, window, x, y);
    DrawCurveLeft(pre_size - 1, length, window, x, y);
    DrawLine(length, 0, window, x, y);
    DrawCurveDown(pre_size - 1, length, window, x, y);
  }
}

void DrawCurveUp(int pre_size, double length, sf::RenderWindow &window, double &x,
              double &y) {
  if (pre_size > 0) {
    DrawCurveLeft(pre_size - 1, length, window, x, y);
    DrawLine(0, -length, window, x, y);
    DrawCurveUp(pre_size - 1, length, window, x, y);
    DrawLine(-length, 0, window, x, y);
    DrawCurveUp(pre_size - 1, length, window, x, y);
    DrawLine(0, length, window, x, y);
    DrawCurveRight(pre_size - 1, length, window, x, y);
  }
}

void DrawCurveDown(int pre_size, double length, sf::RenderWindow &window, double &x,
               double &y) {
  if (pre_size > 0) {
    DrawCurveRight(pre_size - 1, length, window, x, y);
    DrawLine(0, length, window, x, y);
    DrawCurveDown(pre_size - 1, length, window, x, y);
    DrawLine(length, 0, window, x, y);
    DrawCurveDown(pre_size - 1, length, window, x, y);
    DrawLine(0, -length, window, x, y);
    DrawCurveLeft(pre_size - 1, length, window, x, y);
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

  double x = 960 - 25, y = x;

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
  DrawCurveUp(size_curve, length_line, Window, x, y);

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

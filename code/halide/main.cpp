#include <Halide.h>
#include <opencv2/opencv.hpp>
#include <chrono>

int main() {
  // Chargement de l'image à partir du fichier
  std::string inputImagePath = "../../images/inputs/16k.jpg";
  //std::string inputImagePath = "../../images/inputs/balloon.jpg";
  cv::Mat inputImage = cv::imread(inputImagePath, cv::IMREAD_COLOR);

  // Dimensions de l'image
  int width = inputImage.cols;
  int height = inputImage.rows;

  // Conversion de l'image OpenCV en buffer Halide
  Halide::Buffer<uint8_t> input(inputImage.data, width, height, 3); // Spécifier 3 canaux pour l'image couleur

  // Création du buffer de sortie pour l'image transformée
  Halide::Buffer<uint8_t> output(width, height, 3); // Spécifier 3 canaux pour l'image couleur

  // Définition du pipeline de traitement d'images
  Halide::Func invert;
  Halide::Var x, y, c;

  // Mesure du temps de début
  auto start = std::chrono::high_resolution_clock::now();

  // Inversion des couleurs pour chaque canal
  invert(x, y, c) = 255 - input(x, y, c);

  // Génération du code exécutable
  invert.compile_jit();

  // Exécution du pipeline
  invert.realize(output);

  // Mesure du temps de fin
  auto end = std::chrono::high_resolution_clock::now();

  // Calcul de la durée d'exécution en millisecondes
  std::chrono::duration<double, std::milli> duration = end - start;
  double executionTime = duration.count();

  // Conversion du buffer Halide en image OpenCV
  cv::Mat outputImage(height, width, CV_8UC3, output.data()); // Spécifier 3 canaux pour l'image couleur

  // Enregistrement de l'image résultante sur le disque
  std::string outputImagePath = "../../images/outputs/16k_halide.jpg";
  //std::string outputImagePath = "../../images/outputs/balloon_halide.jpg";
  cv::imwrite(outputImagePath, outputImage);

  // Affichage du temps d'exécution
  std::cout << " Halide: Temps d'inversion des couleurs : " << executionTime << " ms" << std::endl;

  return 0;
}

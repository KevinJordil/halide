#include <Halide.h>
#include <opencv2/opencv.hpp>

int main() {
  // Chargement de l'image à partir du fichier
  std::string inputImagePath = "./mongolfiere.jpg";
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

  invert(x, y, c) = 255 - input(x, y, c); // Inversion des couleurs pour chaque canal

  // Génération du code exécutable
  invert.compile_jit();

  // Exécution du pipeline
  invert.realize(output);

  // Conversion du buffer Halide en image OpenCV
  cv::Mat outputImage(height, width, CV_8UC3, output.data()); // Spécifier 3 canaux pour l'image couleur

  // Enregistrement de l'image résultante sur le disque
  std::string outputImagePath = "./new_mongolfiere.jpg";
  cv::imwrite(outputImagePath, outputImage);

  return 0;
}

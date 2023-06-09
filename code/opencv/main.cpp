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

  // Création du Mat de sortie pour l'image transformée
  cv::Mat outputImage(height, width, CV_8UC3);

  // Mesure du temps de début
  auto start = std::chrono::high_resolution_clock::now();

  // Inversion des couleurs pour chaque pixel de l'image
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      cv::Vec3b pixel = inputImage.at<cv::Vec3b>(y, x);
      cv::Vec3b invertedPixel(255 - pixel[0], 255 - pixel[1], 255 - pixel[2]);
      outputImage.at<cv::Vec3b>(y, x) = invertedPixel;
    }
  }

  // Mesure du temps de fin
  auto end = std::chrono::high_resolution_clock::now();

  // Calcul de la durée d'exécution en millisecondes
  std::chrono::duration<double, std::milli> duration = end - start;
  double executionTime = duration.count();

  // Enregistrement de l'image résultante sur le disque
  std::string outputImagePath = "../../images/outputs/16k_opencv.jpg";
  //std::string outputImagePath = "../../images/outputs/balloon_opencv.jpg";
  cv::imwrite(outputImagePath, outputImage);

  // Affichage du temps d'exécution
  std::cout << "Temps d'inversion des couleurs : " << executionTime << " ms" << std::endl;

  return 0;
}
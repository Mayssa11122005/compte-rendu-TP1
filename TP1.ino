#include <WiFi.h>
// Permet d'utiliser le Wi-Fi de l'ESP32.

#include <Wire.h>
// Permet la communication I2C avec l'écran OLED.

#include <Adafruit_GFX.h>
// Permet de gérer les fonctions graphiques de l'écran.

#include <Adafruit_SSD1306.h>
// Permet de contrôler l'écran OLED.

Adafruit_SSD1306 oled(128, 64, &Wire, -1);
// Crée un écran OLED de 128 pixels de largeur et 64 pixels de hauteur.

void setup() {
// Cette fonction s'exécute une seule fois au démarrage.

  Serial.begin(115200);
  // Initialise la communication série à 115200 bauds.

  Wire.begin(21, 22);
  // Configure les broches SDA = 21 et SCL = 22 pour communiquer avec l'écran.

  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  // Initialise l'écran OLED à l'adresse I2C 0x3C.

  oled.setTextColor(SSD1306_WHITE);
  // Définit la couleur du texte en blanc.

  WiFi.mode(WIFI_STA);
  // Configure l'ESP32 en mode station Wi-Fi.

  delay(500);
  // Attend 500 millisecondes.

  oled.clearDisplay();
  // Efface le contenu précédent de l'écran.

  oled.setTextSize(1);
  // Définit la taille du texte.

  oled.setCursor(0, 0);
  // Place le curseur au début de l'écran.

  oled.println("== Infos ESP32 ==");
  // Affiche le titre des informations de l'ESP32.

  oled.printf("Modele: %s\n", ESP.getChipModel());
  // Affiche le modèle de la puce ESP32.

  oled.printf("Coeurs: %d %d MHz\n", ESP.getChipCores(), ESP.getCpuFreqMHz());
  // Affiche le nombre de cœurs et la fréquence du processeur en MHz.

  oled.printf("Flash : %d Mo\n", ESP.getFlashChipSize() / (1024 * 1024));
  // Affiche la taille de la mémoire Flash en mégaoctets.

  oled.printf("RAM : %d o\n", ESP.getFreeHeap());
  // Affiche la quantité de mémoire RAM libre en octets.

  oled.println("MAC :");
  // Affiche le texte MAC.

  oled.println(WiFi.macAddress());
  // Affiche l'adresse MAC de l'ESP32.

  oled.display();
  // Affiche toutes les informations préparées sur l'écran OLED.

  Serial.println("MAC : " + WiFi.macAddress());
  // Affiche l'adresse MAC dans le moniteur série.
}

void loop() {
// Cette fonction se répète en boucle, mais elle ne contient aucune instruction.
}
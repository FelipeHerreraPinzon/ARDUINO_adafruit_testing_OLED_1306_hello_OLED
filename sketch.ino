#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Configuración de pines del OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C  // Asegúrate de usar la dirección correcta (0x3C o 0x3D)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  
  // Inicializar el display OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Detener el programa si la inicialización falla
  }
  
  display.clearDisplay(); // Limpiar pantalla
  display.setTextSize(1); // Tamaño del texto
  display.setTextColor(SSD1306_WHITE); // Color del texto
  display.setCursor(0, 0); // Posición inicial del cursor
  
  // Mostrar un mensaje de prueba
  display.println(F("Hola, OLED!"));
  display.display(); // Actualizar el contenido en la pantalla
}

void loop() {
  // No hacemos nada en el loop para esta prueba
}

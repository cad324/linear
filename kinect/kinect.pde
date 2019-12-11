import org.openkinect.processing.*;
import processing.serial.*;

Kinect kinect;
Serial port;

int pos = 1;
int depth[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

//nums bw 0 and 2048
void setup() {
  println(Serial.list());
  port = new Serial(this, Serial.list()[1], 9600);
  
  // P3D for rendering something in 3D
  size(640, 480, P3D);
  
  // initialize the Kinect
  kinect = new Kinect(this);
  
  kinect.initDepth();
}

void draw() {
  background(0);
  
  // Depth image – 
  PImage img = kinect.getDepthImage();
  
  // Draw the image separately 
  //image(img, 0, 0);
  
  int skip = 512/6;
  
  for (int x = 0; x < img.width; x+=skip) {
    for (int y = 0; y < img.height; y+=skip) {
      
      // Get the pixel in the 1D array
      int index = x + y * img.width;
      
      // Brightness of the pixel at that index
      float b = brightness(img.pixels[index]);
      
      // Map brightness value to a depth
      // Darker object in closer
      int z = (int) map(b, 0, 255, 9, 0);
      port.write(depth[z]);
      
      fill(b);
      
      rect(x, y, skip, skip);
    }
  }
}

import org.openkinect.processing.*;
import processing.serial.*;

Kinect kinect;
Serial portOne;
Serial portTwo;
Serial portThree;

int motor_pos = 29;
int depth[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

//nums bw 0 and 2048
void setup() {
  println(Serial.list());
  
  // Set up the Serial ports
  portOne = new Serial(this, Serial.list()[3], 9600);
  portTwo = new Serial(this, Serial.list()[2], 9600);
  portThree = new Serial(this, Serial.list()[1], 9600);
  portOne.bufferUntil(0x03);
  portTwo.bufferUntil(0x03);
  portThree.bufferUntil(0x03);
  
  // P3D for rendering something in 3D
  size(512, 424, P3D);
  
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
  int count = 0;
  
  for (int x = 0; x < img.width; x+=skip) {
    for (int y = 0; y < img.height; y+=skip) {
      
      // Get the pixel in the 1D array
      int index = x + y * img.width;
      
      // Brightness of the pixel at that index
      float b = brightness(img.pixels[index]);
      
      // Map brightness value to a depth
      // Darker object in closer
      int z = (int) map(b, 0, 255, 9, 0);
      
      if (motor_pos < 10) {
        portOne.write(depth[z]);
      } else if (motor_pos < 20) {
        portTwo.write(depth[z]);
      } else {
        portThree.write(depth[z]);
      }
      
      fill(b);
      
      //rect(img.width-x, img.height-y, -skip, -skip);
      rect(x, y, skip, skip);
      
      motor_pos -= 1;
      if (motor_pos < 0) {
        motor_pos = 29;
      }
    }
  }
}

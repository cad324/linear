import org.openkinect.processing.*;
import processing.serial.*;

Kinect kinect;
Serial port;

int pos = 1;

//nums bw 0 and 2048
void setup() {
  println(Serial.list());
  port = new Serial(this, Serial.list()[1], 9600);
  
  size(512, 424, P3D);
  kinect = new Kinect(this);
  kinect.initDepth();
}

void draw() {
  background(0);
  
  PImage img = kinect.getDepthImage();
  
  int skip = 512/6;
  
  for (int x = 0; x < img.width; x+=skip) {
    for (int y = 0; y < img.height; y+=skip) {
      int index = x + y * img.width;
      float b = brightness(img.pixels[index]);
      //float z = map(b, 0, 255, 150, -150);
      fill(b);
      if (b < 10) {
        port.write('1');
      } else {
        port.write('0');
      //pushMatrix();
      //translate(x, y, z);
        rect(x, y, skip, skip);
      //popMatrix();
      }
    }
  }
}


int x;
int y;

int spacing = 50;

int snakeX = 4;
int snakeY = 4;

int inputDelay = 250;

IntList tailCoords = new IntList();

int direction = 0;

float prevTime;

void setup() {
  size(400,400);
  noStroke();
  prevTime = millis();
  
  tailCoords.push(snakeX);
  tailCoords.push(snakeY);
  
  tailCoords.push(3);
  tailCoords.push(4);
  
  tailCoords.push(2);
  tailCoords.push(4);
}

void draw() {
  background(0);
  
  moveSnake();
  x = 0;
  for(int i = 0; x < width; i++) {
    y = 0;
    for(int j = 0; y < height; j++) {
      fill(255, 255, 255);
      drawSnake(i, j);
      ellipse(x + spacing/2, y + spacing/2, 30, 30);
      y = y + spacing;
    }
    x = x + spacing;
  }
}

void moveSnake() {
  if(snakeY > 8){
    snakeY = 0;
  } else if(snakeY < 0) {
    snakeY = 8;
  } else if(snakeX > 8) {
    snakeX = 0;
  } else if(snakeX < 0) {
    snakeX = 8;
  }
  println(snakeX + " | " + snakeY);
  float currentTime = millis();
  if((currentTime - prevTime) > inputDelay){
    if(direction == 1) {
      snakeY += -1;
    } else if(direction == 2) {
      snakeY += 1;
    } else if(direction == 3) {
      snakeX += -1;
    } else if(direction == 4) {
      snakeX += 1;
    }
    tailCoords = snakeTail();
    prevTime = currentTime;
  }
}

IntList snakeTail() {
  IntList newTailCoords = new IntList();
  for(int i = 0; i < tailCoords.size(); i++){
    if(i == 0){
      newTailCoords.push(snakeX);
    } else if(i == 1){
      newTailCoords.push(snakeY);
    } else {
      newTailCoords.push(tailCoords.get(i - 2));
    }
  }
  return newTailCoords;
}

void drawSnake(int currentX, int currentY) { 
  for(int i = 0; i < tailCoords.size(); i += 2) {
    if(currentX == tailCoords.get(i) && currentY == tailCoords.get(i + 1))
      fill(255, 0, 0);
  }
}

void keyPressed() {
  setMove(keyCode, true);
}
 
boolean setMove(int k, boolean b) {
  switch (k) {
  case UP:
    if(direction != 2)
      direction = 1;
    return b;
  case DOWN:
    if(direction != 1)
      direction = 2;
    return b;
  case LEFT:
    if(direction != 4)
      direction = 3;
    return b;
  case RIGHT:
    if(direction != 3)
      direction = 4;
    return b;
  default:
    return b;
  }
}

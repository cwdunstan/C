#include "filereader.h"

//Creates a new filereader object
//takes in a filepath as input
//reads values from specified lines using a switch / case statement
//error checks results, then assigns read values to local variables
fileReader::fileReader(std::string filePath) {
  QMessageBox error_Message;
  std::set<std::string> playerSizes;
  std::string line;
  std::ifstream infile;
  infile.open(filePath);
  int i = 0;
  if (infile.is_open()) {
    while (getline (infile, line)) {
      switch(i){
      //Player Size, line 2
      case 2: {
        m_size = line;
        if(m_size.compare("tiny") != 0 &&
           m_size.compare("normal") !=0 &&
           m_size.compare("large") !=0 &&
           m_size.compare("giant") != 0){
          error_Message.setText("Player size is not valid.\nOptions are: tiny, normal, large, or giant.");
          error_Message.exec();
          exit(-1);
        }
        break;
      }
      //starting X coordinate, line 4
      case 4: {
        m_xcoord = stoi(line);
        if (m_xcoord < 0) {
          error_Message.setText("X coordinate cannot be negative.");
          error_Message.exec();
          exit(-1);
        }
        break;
      }
      //starting Velocity, line 6
      case 6: {
        m_velocity=stoi(line);
        if (m_velocity < 0) {
          error_Message.setText("Initial velocity cannot be negative.");
          error_Message.exec();
          exit(-1);
        }
        break;
      }
      //filepath for background image, line 8
      case 8: {
        m_bgPath=line;
        std::ifstream check_valid(line);
        if (!check_valid) {
          error_Message.setText("Invalid background image path.");
          error_Message.exec();
          exit(-1);
        }
        break;
      }
      //framewidth, line 10
      case 10: {
        m_frameWidth=stoi(line);
        if (m_xcoord < 0) {
          error_Message.setText("Frame Width cannot be negative.");
          error_Message.exec();
          exit(-1);
        }
        break;
      }
      //frameheight, line 12
      case 12: {
        m_frameHeight=stoi(line);
        if (m_xcoord < 0) {
          error_Message.setText("Frame Height cannot be negative.");
          error_Message.exec();
          exit(-1);
        }
        break;
      }
    }
    i++;
  }
  infile.close();
} else {
  //filepath not found
  error_Message.setText("Error Opening File.\nPlease check file path, and try again.");
  error_Message.exec();
  exit(-1);
  }
}
//General getter functions for filereader values
std::string fileReader::getBgPath() {
  return m_bgPath;
}

int fileReader::getFrameHeight() {
  return m_frameHeight;
}

int fileReader::getFrameWidth() {
  return m_frameWidth;
}

std::string fileReader::getSize() {
  return m_size;
}

int fileReader::getVelocity() {
  return m_velocity;
}

int fileReader::getX() {
  return m_xcoord;
}

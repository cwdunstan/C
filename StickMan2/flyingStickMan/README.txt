*****************  FLYING STICKMAN  **************************

Style Guide Used:
Google C++ (https://google.github.io/styleguide/cppguide.html#Comments) 
with the following variations:
 - does not include legal notice / author line 
 - class comments provide descriptions, but not implementation examples
 - global variables do not have specific comments describing them
 - local variables follow the format: m_myvariable


Current Features:
 - Reads values from config file (with error checking) into a 'filereader object'.
 - implements factory pattern to create player objects of sizes: tiny, normal, large, giant.
 - implements factory pattern to create game object of background (more can be added).
 - includes background music (from the internet, not orginial composition)
 - Includes two keypress functions:
    * press P to pause game play, and again to resume.
    * press O to enter hard mode, and again to revert to normal.


Resource Management:
certain files (i.e. music files, hard mode background image) are specified within the code, while others (background image) are specified in config file. this to allow a certain degree of user customization, but may be modified in future for more flexibility.


StickMan Drawing:
Currently stickman is drawn entierly using vectory and QT shapes. Currently using frameheight and width this scales accordingly, but may prove tricky in future iterations, especailly when collision detection is added.
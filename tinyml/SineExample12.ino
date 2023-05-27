#include <EloquentTinyML.h>
#include <eloquent_tinyml/tensorflow.h>

#include "sine_model.h"

#define NUMBER_OF_INPUTS 60
#define NUMBER_OF_OUTPUTS 1
#define TENSOR_ARENA_SIZE 8 * 1024

Eloquent::TinyML::TensorFlow::TensorFlow<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> tf;

void setup() {
  Serial.begin(115200);
  tf.begin(sine_model);
}

void loop() {
  Serial.println("Model is running");

  float X_test[60] = {0.0453,0.0523,  0.0843 , 0.0689,  0.1183 , 0.2583,  0.2156,  0.3481,  0.3337 , 0.2872 , 0.4918  ,0.6552,  0.6919,  0.7797,  0.7464,  0.9444,  1, 0.8874 , 0.8024,  0.7818 , 0.5212,  0.4052 , 0.3957 , 0.3914,  0.325 ,0.32,  0.3271,  0.2767 , 0.4423,  0.2028,  0.3788,  0.2947 , 0.1984  ,0.2341 , 0.1306 , 0.4182,  0.3835 , 0.1057  ,0.184, 0.197, 0.1674 , 0.0583 , 0.1401 , 0.1628 , 0.0621 , 0.0203 , 0.053 ,0.0742 , 0.0409 , 0.0061 , 0.0125 , 0.0084  ,0.0089,  0.0048 , 0.0094,  0.0191 , 0.014, 0.0049 , 0.0052 , 0.0044};
    float predicted=tf.predict(X_test);
    Serial.println(predicted);
  
  delay(1000);
}

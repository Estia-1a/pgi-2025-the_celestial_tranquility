#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}




void dimension (char *source_path){
    int width;
    int height;
    int channel_count;
    unsigned char *data;

    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    
    if (resultat){
        printf("dimension: %d, %d\n", width, height);
    
    }
    else {
        printf("erreur:");
    }
}
   
    

void first_pixel (char *source_path){
    int width;
    int height;
    int channel_count;
    unsigned char *data;

    int couleur = read_image_data(source_path, &data, &width, &height, &channel_count);
    int R=data[0], G=data[1], B=data[2];

    if (couleur){
        printf("first_pixel: %d, %d, %d", R, G, B);
    }
    else {
        printf("erreur:");
    }
    
}


void tenth_pixel (char *source_path){
    int width;
    int height;
    int channel_count;
    unsigned char *data;

    int couleur = read_image_data(source_path, &data, &width, &height, &channel_count);
    int R=data[27], G=data[28], B=data[29];

    if (couleur){
        printf("first_pixel: %d, %d, %d", R, G, B);
    }
    else {
        printf("erreur:");
    }
    
}


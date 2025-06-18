#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("tenth_pixel: %d, %d, %d",R,G,B);
    }
    else {
        printf("erreur:");
    }
    
}

void second_line(char *source_path){
    int width;
    int height;
    int channel_count;
    unsigned char *data;

    int couleur = read_image_data(source_path, &data, &width, &height, &channel_count);
    int R=data[width*3*1], G=data[width*3*1+1], B=data[width*3*1+2];

    if (couleur){
        printf("second_line: %d, %d, %d", R, G, B);
    }
    else {
        printf("erreur:");
    }
}
    
    
    
void print_pixel(char *source_path, int x, int y ){

    int width;
    int height;
    int channel_count;
    unsigned char *data;

    int couleur = read_image_data(source_path, &data, &width, &height, &channel_count);
    int R = data[(y * width + x) * 3], G = data[(y * width + x) * 3 + 1], B = data[(y * width + x) * 3 + 2];

    if (couleur){
        printf("print_pixel (%d, %d): %d, %d, %d", x, y, R, G, B);
    }
    else {
        printf("erreur:");
    }
}

void max_pixel(char *source_path){
    unsigned char *data;
    int x, y;
    int height,width,channel_count;
    int status= read_image_data(source_path, &data, &width, &height, &channel_count);
    int max_rgb_sum =0;
    int max1 = 0, max2= 0;
    int rgb_sum, R,G,B;
 
    if (status!=0){
 
            for (y= 0; y< height; y++) {
                for (x= 0; x < width; x++) {
                    R = (y*width+x)*channel_count;
                    G = (y*width+x)*channel_count + 1;
                    B = (y*width+x)*channel_count + 2;
 
                    rgb_sum = data[R] + data[G] + data[B];
                    if (rgb_sum > max_rgb_sum) {
                        max_rgb_sum = rgb_sum;
                        max1 = x;
                        max2= y;
                    }
                }
            }
 
            R = (max2*width+max1)*channel_count;
            G = (max2*width+max1)*channel_count + 1;
            B = (max2*width+max1)*channel_count + 2;
 
            printf("max_pixel(%d, %d): %d, %d, %d\n", max1, max2, data[R], data[G], data[B]);
    }
    else{
        printf("error");
    }
}



void max_component(char *source_path,char *pixel){

    unsigned char *data;

    int x,y;

    int height,width,channel_count;

    int status= read_image_data(source_path, &data, &width, &height, &channel_count);

    int max_rgb_sum =0;

    int max1 = 0, max2 = 0;

    int rgb_sum,result;
 
    if (status!=0){

            if(strcmp(pixel, "R") == 0){

                 result=0;

            }

            else if(strcmp(pixel, "G") == 0) {

                result=1;

            }

            else if(strcmp(pixel, "B") == 0)  {

                result=2;

            }
 
            for (y= 0; y< height; y++) {

                for (x= 0; x < width; x++) {

                    rgb_sum= (y*width+x)*channel_count + result;

                    if (data[rgb_sum]>max_rgb_sum) {

                        max_rgb_sum = data[rgb_sum];

                        max1=x;

                        max2=y;

                    }

                }

            }
 
 
            int R1 = (max2*width+max1)*channel_count;

            int G1 = (max2*width+max1)*channel_count + 1;

            int B1 = (max2*width+max1)*channel_count + 2;
 
            if (strcmp(pixel,"R")==0){

                printf("max_component R (%d, %d): %d \n", max1, max2, data[R1]);

            }
 
             if (strcmp(pixel,"G")==0){

                printf("max_component G (%d, %d): %d \n", max1, max2, data[G1]);

            }
 
             if (strcmp(pixel,"B")==0){

                printf("max_component B (%d, %d): %d \n", max1, max2, data[B1]);

            }
 
    }

    else{

        printf("An error occured");

    }

}   


void min_component(char *source_path,char *pixel){

    unsigned char *data;

    int x,y;

    int height,width,channel_count;

    int status= read_image_data(source_path, &data, &width, &height, &channel_count);

    int min_rgb_sum =256;

    int min1 = 0, min2 = 0;

    int rgb_sum,result;
 
    if (status!=0){

            if(strcmp(pixel, "R") == 0){

                 result=0;

            }

            else if(strcmp(pixel, "G") == 0) {

                result=1;

            }

            else if(strcmp(pixel, "B") == 0)  {

                result=2;

            }
 
            for (y= 0; y< height; y++) {

                for (x= 0; x < width; x++) {

                    rgb_sum= (y*width+x)*channel_count + result;

                    if (data[rgb_sum]<min_rgb_sum) {

                        min_rgb_sum = data[rgb_sum];

                        min1=x;

                        min2=y;

                    }

                }

            }

            printf("min_component %s (%d, %d): %d\n",pixel, min1, min2,min_rgb_sum);

    }

    else{

        printf("error");

    }

}

 
 void min_pixel(char *source_path){
    unsigned char *data;
    int x, y;
    int height,width,channel_count;
    int status= read_image_data(source_path, &data, &width, &height, &channel_count);
    int min_rgb_sum =256*3;
    int min1 = 0, min2= 0;
    int rgb_sum, R,G,B;
 
    if (status!=0){
 
            for (y= 0; y< height; y++) {
                for (x= 0; x < width; x++) {
                    R = (y*width+x)*channel_count;
                    G = (y*width+x)*channel_count + 1;
                    B = (y*width+x)*channel_count + 2;
 
                    rgb_sum = data[R] + data[G] + data[B];
                    if (rgb_sum < min_rgb_sum) {
                        min_rgb_sum = rgb_sum;
                        min1 = x;
                        min2= y;
                    }
                }
            }
 
            R = (min2*width+min1)*channel_count;
            G = (min2*width+min1)*channel_count + 1;
            B = (min2*width+min1)*channel_count + 2;
 
            printf("min_pixel(%d, %d): %d, %d, %d\n", min1, min2, data[R], data[G], data[B]);
    }
    else{
        printf("error");
    }
 }
void color_red(char* source_path){

    unsigned char* image_data = NULL;

    int img_width = 0, img_height = 0, channels = 0;
 
    read_image_data(source_path, &image_data, &img_width, &img_height, &channels);
 
    int pixel_count = img_width * img_height;
 
    for (int p = 0; p < pixel_count; ++p) {

        int offset = p * channels;

        if (channels >= 3) {

            image_data[offset + 1] = 0; // green

            image_data[offset + 2] = 0; // blue

        }

    }
 
    const char* output_path = "image_out.bmp";

    write_image_data(output_path, image_data, img_width, img_height);

}
 
void color_blue(char* source_path){

    unsigned char* image_data = NULL;

    int img_width = 0, img_height = 0, channels = 0;
 
    read_image_data(source_path, &image_data, &img_width, &img_height, &channels);
 
    int pixel_count = img_width * img_height;
 
    for (int p = 0; p < pixel_count; ++p) {

        int offset = p * channels;

        if (channels >= 3) {

            image_data[offset + 0] = 0; // red

            image_data[offset + 1] = 0; // green

        }

    }
 
    const char* output_path = "image_out.bmp";

    write_image_data(output_path, image_data, img_width, img_height);

}

void color_green(char* source_path){

    unsigned char* image_data = NULL;

    int img_width = 0, img_height = 0, channels = 0;
 
    read_image_data(source_path, &image_data, &img_width, &img_height, &channels);
 
    int pixel_count = img_width * img_height;
 
    for (int p = 0; p < pixel_count; ++p) {

        int offset = p * channels;

        if (channels >= 3) {

            image_data[offset + 0] = 0; // red

            image_data[offset + 2] = 0; // blue

        }

    }
 
    const char* output_path = "image_out.bmp";

    write_image_data(output_path, image_data, img_width, img_height);

}

void color_gray(char* source_path) {

    unsigned char* image_data = NULL;
    int img_width = 0, img_height = 0, channels = 0;

    read_image_data(source_path, &image_data, &img_width, &img_height, &channels);

    int pixel_count = img_width * img_height;

    for (int p = 0; p < pixel_count; ++p) {
        int offset = p * channels;

        if (channels >= 3) {
            unsigned char R = image_data[offset + 0];
            unsigned char G = image_data[offset + 1];
            unsigned char B = image_data[offset + 2];

            unsigned char value = (R + G + B) / 3;

            image_data[offset + 0] = value; // red
            image_data[offset + 1] = value; // green
            image_data[offset + 2] = value; // blue
        }
    }

    const char* output_path = "image_out.bmp";
    write_image_data(output_path, image_data, img_width, img_height);
}

void color_gray_luminance(char* source_path) {

    unsigned char* image_data = NULL;
    int img_width = 0, img_height = 0, channels = 0;

    read_image_data(source_path, &image_data, &img_width, &img_height, &channels);

    int pixel_count = img_width * img_height;

    for (int p = 0; p < pixel_count; ++p) {
        int offset = p * channels;

        if (channels >= 3) {
            unsigned char R = image_data[offset + 0];
            unsigned char G = image_data[offset + 1];
            unsigned char B = image_data[offset + 2];

            unsigned char value = (R*0.21 + G*0.72 + B*0.07);

            image_data[offset + 0] = value; // red
            image_data[offset + 1] = value; // green
            image_data[offset + 2] = value; // blue
        }
    }

    const char* output_path = "image_out.bmp";
    write_image_data(output_path, image_data, img_width, img_height);
}

void color_invert(char* source_path) {



}

void color_desaturate(char* source_path) {



}

void stat_report(char* source_path) {



}
#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
    unsigned char *image_data = NULL;
    int img_width = 0, img_height = 0, channels = 0;

    read_image_data(source_path, &image_data, &img_width, &img_height, &channels);

    for (int y = 0; y < img_height; y++) {
        for (int x = 0; x < img_width; x++) {
            int offset = channels * (x + y * img_width);

            // Inverser chaque composante de couleur (RGB)
            unsigned char red   = image_data[offset];
            unsigned char green = image_data[offset + 1];
            unsigned char blue  = image_data[offset + 2];

            image_data[offset]     = 255 - red;
            image_data[offset + 1] = 255 - green;
            image_data[offset + 2] = 255 - blue;
        }
    }

    const char* output_path = "image_out.bmp";
    write_image_data(output_path, image_data, img_width, img_height);
}

    void color_desaturate(char* source_path) {

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

            unsigned char gray = round((fmin(fmin(R, G), B) + fmax(fmax(R, G), B)) / 2.0);

            image_data[offset + 0] = gray;
            image_data[offset + 1] = gray;
            image_data[offset + 2] = gray;
        }
    }

    const char* output_path = "image_out.bmp";
    write_image_data(output_path, image_data, img_width, img_height);


}

void stat_report(char *source_path) {
    FILE *f = fopen("stat_report.txt", "w");
    if (!f) return;

    unsigned char *img;
    int w, h, c;
    int status = read_image_data((const char *)source_path, &img, &w, &h, &c); 
    if (!status) {
        fclose(f);
        return;
    }

    int x, y, i, r, g, b, s;
    int maxs = 0, mins = 256 * 3, xmax = 0, ymax = 0, xmin = 0, ymin = 0;
    int rmax = 0, gmax = 0, bmax = 0, rmin = 255, gmin = 255, bmin = 255;
    int rxmax = 0, rymax = 0, gxmax = 0, gymax = 0, bxmax = 0, bymax = 0;
    int rxmin = 0, rymin = 0, gxmin = 0, gymin = 0, bxmin = 0, bymin = 0;

    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            i = (y * w + x) * c;
            r = img[i];
            g = img[i + 1];
            b = img[i + 2];
            s = r + g + b;

            if (s > maxs) { maxs = s; xmax = x; ymax = y; }
            if (s < mins) { mins = s; xmin = x; ymin = y; }

            if (r > rmax) { rmax = r; rxmax = x; rymax = y; }
            if (g > gmax) { gmax = g; gxmax = x; gymax = y; }
            if (b > bmax) { bmax = b; bxmax = x; bymax = y; }

            if (r < rmin) { rmin = r; rxmin = x; rymin = y; }
            if (g < gmin) { gmin = g; gxmin = x; gymin = y; }
            if (b < bmin) { bmin = b; bxmin = x; bymin = y; }
        }
    }

    fprintf(f, "max_pixel(%d, %d): %d, %d, %d\n\n", xmax, ymax, img[(ymax * w + xmax) * c], img[(ymax * w + xmax) * c + 1], img[(ymax * w + xmax) * c + 2]);
    fprintf(f, "min_pixel(%d, %d): %d, %d, %d\n\n", xmin, ymin, img[(ymin * w + xmin) * c], img[(ymin * w + xmin) * c + 1], img[(ymin * w + xmin) * c + 2]);
    fprintf(f, "max_component R (%d, %d): %d\n\n", rxmax, rymax, rmax);
    fprintf(f, "max_component G (%d, %d): %d\n\n", gxmax, gymax, gmax);
    fprintf(f, "max_component B (%d, %d): %d\n\n", bxmax, bymax, bmax);
    fprintf(f, "min_component R (%d, %d): %d\n\n", rxmin, rymin, rmin);
    fprintf(f, "min_component G (%d, %d): %d\n\n", gxmin, gymin, gmin);
    fprintf(f, "min_component B (%d, %d): %d\n\n", bxmin, bymin, bmin);

    fclose(f);
}

/*void rotate_cw(char *source_path) {



}

void rotate_acw(char *source_path) {


    
}*/

void mirror_horizontal(char *source_path) {
    unsigned char *contenu;
    int lx, ly, nb;
    read_image_data(source_path, &contenu, &lx, &ly, &nb);

    for (int j = 0; j < ly; j++) {
        for (int i = 0; i < lx / 2; i++) {
            int d1 = (j * lx + i) * nb;
            int d2 = (j * lx + (lx - i - 1)) * nb;

            for (int k = 0; k < 3; k++) {
                unsigned char temp = contenu[d1 + k];
                contenu[d1 + k] = contenu[d2 + k];
                contenu[d2 + k] = temp;
            }
        }
    }

    write_image_data("image_out.bmp", contenu, lx, ly);
}


void mirror_vertical(char *source_path) {
    unsigned char *contenu;
    int lx, ly, nb;
    read_image_data(source_path, &contenu, &lx, &ly, &nb);

    for (int j = 0; j < ly / 2; j++) {
        for (int i = 0; i < lx; i++) {
            int a = (j * lx + i) * nb;
            int b = ((ly - 1 - j) * lx + i) * nb;
            for (int k = 0; k < 3; k++) {
                unsigned char tmp = contenu[a + k];
                contenu[a + k] = contenu[b + k];
                contenu[b + k] = tmp;
            }
        }
    }

    write_image_data("image_out.bmp", contenu, lx, ly);
}


    
void mirror_total(char *source_path) {
    unsigned char *contenu;
    int lx, ly, nb;
    read_image_data(source_path, &contenu, &lx, &ly, &nb);

    for (int j = 0; j < ly / 2; j++) {
        for (int i = 0; i < lx; i++) {
            int a = (j * lx + i) * nb;
            int b = ((ly - 1 - j) * lx + (lx - 1 - i)) * nb;
            for (int k = 0; k < 3; k++) {
                unsigned char tmp = contenu[a + k];
                contenu[a + k] = contenu[b + k];
                contenu[b + k] = tmp;
            }
        }
    }

    if (ly % 2 == 1) {
        int m = ly / 2;
        for (int i = 0; i < lx / 2; i++) {
            int a = (m * lx + i) * nb;
            int b = (m * lx + (lx - 1 - i)) * nb;
            for (int k = 0; k < 3; k++) {
                unsigned char tmp = contenu[a + k];
                contenu[a + k] = contenu[b + k];
                contenu[b + k] = tmp;
            }
        }
    }
    write_image_data("image_out.bmp", contenu, lx, ly);
}

void scale_crop(char *source_path) {
    unsigned char *data;
    int iw, ih, c, cx, cy, tw, th;
    read_image_data(source_path, &data, &iw, &ih, &c);

    int x0 = cx - tw / 2;
    int y0 = cy - th / 2;

    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x0 + tw > iw) x0 = iw - tw;
    if (y0 + th > ih) y0 = ih - th;
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;

    for (int j = 0; j < th; j++) {
        for (int i = 0; i < tw; i++) {
            int src = ((y0 + j) * iw + (x0 + i)) * c;
            data[(j * tw + i) * c + 0] = data[src + 0];
            data[(j * tw + i) * c + 1] = data[src + 1];
            data[(j * tw + i) * c + 2] = data[src + 2];
        }
    }

    write_image_data("image_out.bmp", data, tw, th);
}
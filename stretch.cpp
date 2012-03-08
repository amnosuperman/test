//Program to stretch the central 1/5th horizontal and vertical strip of the image  
//to 1/3rd of the image and to compress the remaining portions so that the image is continuous.

#include<cv.h>
#include<highgui.h>
#include<stdio.h>
int main( int argc, char** argv ) 
{
cvNamedWindow( "Original", CV_WINDOW_AUTOSIZE );
cvNamedWindow( "Stretched", CV_WINDOW_AUTOSIZE );
CvCapture* capture;
IplImage* frame1;
if(argc==1)
{
capture = cvCreateCameraCapture(0);
} 
else 
{
capture = cvCreateFileCapture( argv[1] );
}
assert( capture != NULL );
int max=0;
while(1) 
{
frame1 = cvQueryFrame( capture );
CvMat t = cvMat(frame1->width,frame1->height,CV_8UC3,(unsigned char*)frame1->imageData);
IplImage* frame = cvCreateImage(cvGetSize(frame1),8,3);
frame->imageData = (char*)t.data.ptr;
IplImage* image = cvCreateImage(cvGetSize(frame),IPL_DEPTH_8U,3);
IplImage* image1 = cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,3);
cvSetImageROI(frame,cvRect(0,0,640,192));
cvSetImageROI(image,cvRect(0,0,640,160));
cvResize(frame,image);
cvResetImageROI(image);
cvResetImageROI(frame);

cvSetImageROI(frame,cvRect(0,192,640,96));
cvSetImageROI(image,cvRect(0,160,640,160));
cvResize(frame,image);
cvResetImageROI(image);
cvResetImageROI(frame);

cvSetImageROI(frame,cvRect(0,288,640,192));
cvSetImageROI(image,cvRect(0,320,640,160));
cvResize(frame,image);
cvResetImageROI(image);
cvResetImageROI(frame);

cvSetImageROI(image,cvRect(0,0,256,480));
cvSetImageROI(image1,cvRect(0,0,213,480));
cvResize(image,image1);
cvResetImageROI(image1);
cvResetImageROI(image);

cvSetImageROI(image,cvRect(256,0,128,480));
cvSetImageROI(image1,cvRect(213,0,213,480));
cvResize(image,image1);
cvResetImageROI(image1);
cvResetImageROI(image);

cvSetImageROI(image,cvRect(384,0,256,480));
cvSetImageROI(image1,cvRect(426,0,214,480));
cvResize(image,image1);
cvResetImageROI(image1);
cvResetImageROI(image);

if( !frame ) break;
{
cvShowImage( "Original", frame );
cvShowImage( "Stretched", image1 );
}
char c = cvWaitKey(33);
if( c == 27 ) break;
}
cvWaitKey(0);
cvDestroyWindow( "Stretched" );
cvReleaseCapture( &capture );
cvDestroyWindow( "Orgignal" );
}

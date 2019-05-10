#include<iostream>
#include<conio.h>
#include "highgui.h"
using namespace std;

int main(int argc, char** argv)
{
int ch;
do
{
    cout<<"\n1. zooming using bicubic interpolation "<<endl;
    cout<<"2. zooming using bilinear interpolation "<<endl;
    cout<<"3. shrinking using bicubic interpolation"<<endl;
    cout<<"4. shrinking using bilinear interpolation"<<endl;
    cout<<"0. exit"<<endl;
    cout<<"enter choice : "<<endl;
    cin>>ch;
          if(ch==1 || ch==2)
          {
          IplImage* img = cvLoadImage("zoom_her.JPG");
          cvNamedWindow("proj", CV_WINDOW_AUTOSIZE);
          cvShowImage("proj", img);
          cvWaitKey(0);
          cvDestroyWindow("proj");

                if(ch==1)
                    {
                    cout<<"\nZooming using BiCubic Interpolation";
                    IplImage *destination1 = cvCreateImage(cvSize(960,637),img->depth,img->nChannels);
                    cvResize(img, destination1, CV_INTER_CUBIC);
                    cvNamedWindow("proj2", CV_WINDOW_AUTOSIZE);
                    cvShowImage("proj2", destination1);
                    cvWaitKey(0);
                    cvReleaseImage( &destination1);
                    cvDestroyWindow("proj2");
                    }
                else
                    {
                    cout<<"\nZooming using Bilinear Interpolation";
                    IplImage *destination2 = cvCreateImage(cvSize(960,637),img->depth,img->nChannels);
                    cvResize(img, destination2, CV_INTER_LINEAR);
                    cvNamedWindow("proj3", CV_WINDOW_AUTOSIZE);
                    cvShowImage("proj3", destination2);
                    cvWaitKey(0);
                    cvReleaseImage( &destination2);
                    cvDestroyWindow("proj3");
                                        }
          }
              if(ch==3 || ch==4)
              {
                IplImage* img = cvLoadImage("zoom_her.JPG");
                cvNamedWindow("proj", CV_WINDOW_AUTOSIZE);
                cvShowImage("proj", img);
                cvWaitKey(0);
                cvDestroyWindow("proj");
                if(ch==3)
                        {
                          cout<<"\nShrinking using Bicubic Interpolation";
                        IplImage *destination1 = cvCreateImage(cvSize(256,256),img->depth,img->nChannels);
                        cvResize(img, destination1, CV_INTER_CUBIC);
                        cvNamedWindow("proj2", CV_WINDOW_AUTOSIZE);
                        cvShowImage("proj2", destination1);
                        cvWaitKey(0);
                        cvReleaseImage( &destination1);
                        cvDestroyWindow("proj2");
                                                }
                        else
                        {
                          cout<<"\nShrinking using Bilinear Interpolation";
                        IplImage *destination2 = cvCreateImage(cvSize(256,256),img->depth,img->nChannels);
                        cvResize(img, destination2, CV_INTER_LINEAR);
                        cvNamedWindow("proj3", CV_WINDOW_AUTOSIZE);
                        cvShowImage("proj3", destination2);
                        cvWaitKey(0);
                        cvReleaseImage( &destination2);
                        cvDestroyWindow("proj3");
                        }
                }
}
while(ch!=0);
return 0;
}

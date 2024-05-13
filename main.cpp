//Number 1
/*
#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main()
{
   Mat src = imread("C:\\Users\\Admin\\Desktop\\labelex.png", IMREAD_GRAYSCALE);
   if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
   Mat bin;
   threshold(src, bin, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
   Mat labels, stats, centroids;
   int cnt = connectedComponentsWithStats(bin, labels, stats, centroids);
   int max = 1, min = 1;
   for (int i = 2; i < cnt; i++) {
      int* mx = stats.ptr<int>(max);
      int* mn = stats.ptr<int>(min);
      int* p = stats.ptr<int>(i); //stats��ü�� i���� �����ּҸ� ����
      if (p[2] * p[3] > mx[2] * mx[3]) max = i;
      if (p[2] * p[3] < mn[2] * mn[3]) min = i;
   }
   Mat dst;
   cvtColor(src, dst, COLOR_GRAY2BGR);

   int* mxp = stats.ptr<int>(max); //stats��ü�� i���� �����ּҸ� ����
   int* mnp = stats.ptr<int>(min); //stats��ü�� i���� �����ּҸ� ����
   rectangle(dst, Rect(mxp[0], mxp[1], mxp[2], mxp[3]), Scalar(0, 0, 255));
   rectangle(dst, Rect(mnp[0], mnp[1], mnp[2], mnp[3]), Scalar(255, 0, 0));
   double* mxpc = centroids.ptr<double>(max);
   double* mnpc = centroids.ptr<double>(min);
   cout << "������ �ִ��� ��ü�� ���̺� : " << max << endl;
   cout << "�����߽� : (x,y) : " << mxpc[0] << "\t" << mxpc[1] << endl;

   cout << "������ �ּ��� ��ü�� ���̺� : " << min << endl;
   cout << "�����߽� : (x,y) : " << mnpc[0] << "\t" << mnpc[1] << endl;

   imshow("src", src);
   imshow("dst", dst);
   waitKey();
   return 0;
}
*/

//Number 2
/*
#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main()
{
   Mat src = imread("D:\\Users\\Admin\\opencv\\polygon.bmp");
   if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
   Mat bin, gray;
   cvtColor(src, gray, COLOR_BGR2GRAY);
   threshold(gray, bin, 150, 255, THRESH_BINARY_INV);
   Mat labels, stats, centroids;
   int cnt = connectedComponentsWithStats(bin, labels, stats, centroids);
   cout << endl << centroids << endl;
   cout << "label\tx\ty\twidth\theight\tarea\tcolor:[B,G,R]" << endl;
   for (int i = 1; i < cnt; i++) {
      int* p = stats.ptr<int>(i);
      double* cp = centroids.ptr<double>(i);
      cout << i << "\t" << p[0] << "\t" << p[1] << "\t" << p[2] << "\t" <<
         p[3] << "\t" << p[2] * p[3] << "\t" << src.at<Vec3b>(cp[1], cp[0]) << endl;
      rectangle(src, Rect(p[0], p[1], p[2], p[3]), Scalar(0, 255, 255));
      putText(src, to_string(i), Point((int)cp[0], (int)cp[1]), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 100, 255));
      cout << cp[0] << "  " << cp[1] << endl;
   }

   imshow("src", src);
   imshow("gray", gray);
   imshow("bin", bin);
   waitKey();
   return 0;
}
*/

//Number 3
/*
#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main()
{
    Mat src = imread("D:\\Users\\Admin\\opencv\\polygon.bmp");
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
    Mat bin, gray;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    threshold(gray, bin, 150, 255, THRESH_BINARY_INV);
    Mat labels, stats, centroids;
    int cnt = connectedComponentsWithStats(bin, labels, stats, centroids);
    for (int i = 1; i < cnt; i++) {
        double* cp = centroids.ptr<double>(i);
        string str = to_string(i) + "��° �����߽� : ";
        cout << str << cp[0] << ", " << cp[1] << endl;
    }

    cout << "����� ���� ��� �����߽�" << endl;
    for (int i = 1; i < cnt; i++) {
        int* p = stats.ptr<int>(i);
        int count = 0;
        float xsum = 0, ysum = 0;
        for (int x = p[0]; x < p[0] + p[2]; x++) {
            for (int y = p[1]; y < p[1]+p[3]; y++) {
                if (bin.at<uchar>(y, x) == 255) {
                    count++;
                    xsum += x;
                    ysum += y;
                }
            }
        }
        cout << i << "�� ��ü�� �����߽�:(" << xsum / count << ", " << ysum / count << ")" << endl;
    }
    return 0;
}
*/

//Numebr 4
/*
#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main()
{
   Mat src = imread("C:\\Users\\Admin\\Desktop\\car.jpg");
   if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
   Mat bin;
   threshold(src, bin, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
   Mat labels, stats, centroids;
   int cnt = connectedComponentsWithStats(bin, labels, stats, centroids);
   int max = 1, min = 1;
   for (int i = 2; i < cnt; i++) {
      int* mx = stats.ptr<int>(max);
      int* mn = stats.ptr<int>(min);
      int* p = stats.ptr<int>(i); //stats��ü�� i���� �����ּҸ� ����
      if (p[2] * p[3] > mx[2] * mx[3]) max = i;
      if (p[2] * p[3] < mn[2] * mn[3]) min = i;
   }
   Mat dst;
   cvtColor(src, dst, COLOR_GRAY2BGR);

   int* mxp = stats.ptr<int>(max); //stats��ü�� i���� �����ּҸ� ����
   int* mnp = stats.ptr<int>(min); //stats��ü�� i���� �����ּҸ� ����
   rectangle(dst, Rect(mxp[0], mxp[1], mxp[2], mxp[3]), Scalar(0, 0, 255));
   rectangle(dst, Rect(mnp[0], mnp[1], mnp[2], mnp[3]), Scalar(255, 0, 0));
   double* mxpc = centroids.ptr<double>(max);
   double* mnpc = centroids.ptr<double>(min);
   cout << "������ �ִ��� ��ü�� ���̺� : " << max << endl;
   cout << "�����߽� : (x,y) : " << mxpc[0] << "\t" << mxpc[1] << endl;

   cout << "������ �ּ��� ��ü�� ���̺� : " << min << endl;
   cout << "�����߽� : (x,y) : " << mnpc[0] << "\t" << mnpc[1] << endl;

   imshow("src", src);
   imshow("dst", dst);
   waitKey();
   return 0;
}
*/

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {
    Mat src = imread("D:\\Users\\Admin\\opencv\\car.jpg", IMREAD_GRAYSCALE);
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
    imshow("src", src);
    waitKey(2000);
    Mat br, sobel, bin, mopo;
    blur(src, br, Size(5, 5));
    Sobel(br, sobel, -1, 1, 0);
    imshow("x�� ���� �Һ�", sobel);
    waitKey(2000);
    threshold(sobel, bin, 150, 255, CV_8U);
    imshow("����ȭ �� ����", src);
    waitKey(2000);
    Mat M = getStructuringElement(MORPH_RECT, Size(50, 5));
    morphologyEx(bin, mopo, MORPH_CLOSE, M);
    morphologyEx(mopo, mopo, MORPH_CLOSE, Mat(9, 3 ,CV_8U));
    Mat labels, stats, centroids;
    int cnt = connectedComponentsWithStats(mopo, labels, stats, centroids);
    int max = 1;
    for (int i = 2; i < cnt; i++) {
        int* mx = stats.ptr<int>(max);
        int* p = stats.ptr<int>(i); //stats��ü�� i���� �����ּҸ� ����
        if (p[2] * p[3] > mx[2] * mx[3]) max = i;
    }
    int* p = stats.ptr<int>(max); //stats��ü�� i���� �����ּҸ� ����
    cvtColor(src, src, COLOR_GRAY2BGR);
    rectangle(src, Rect(p[0], p[1], p[2], p[3]), Scalar(0, 0, 255), 2);
    imshow("src", src);
    waitKey();
    return 0;
}

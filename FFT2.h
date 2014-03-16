/**
 * \file FFT2.h
 * \brief Computation of the FFT-2D
 * \version 1.0
 * \date July 30, 2013
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the distribution
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FFT2_H_
#define FFT2_H_

#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace cv;

/*! \class FFT2
   * \brief   This class is used to compute the 2D-Fast Fourier Transform
   *
   */
class FFT2 : public Mat{

protected:
	Mat X;			/*!< A gray level image */
	/*!
	 *  \brief Compute the FFT2
	 *
	 *   \return The FFT2 of the image given in the constructor
	 */
	Mat computeFFT2();
	/*!
	 *  \brief Compute the iFFT2
     *
     *   \return The iFFT2 of the image given in the constructor
	 */
	Mat computeiFFT2();
public:
	FFT2();
	/*!
	 *  \brief Constructor of FFT2 class
	     *
	     *  \param X : A gray level image
	     */
	FFT2(Mat X);
	/*!
	 *  \brief Constructor
	     *
	     *  Constructor of FFT2 class
	     *
	     *  \param X : A Mat which contains a gray level image
	     *  \param inverse : If inverse==-1 the inverse Fast Fourier Transform is computed (iFFT2) else the Fast Fourier Transform is computed
	     *
	     */
	FFT2(Mat X,int inverse);
	/*!
	 *  \brief Compute the magnitude of the FFT2
	 *
	 *  \return the magnitude of the FFT2
	 */
	Mat magnitude();
	/*!
	 *  \brief Set the FFT2
	 *
	 */
	void setFFT2(const Mat& fft2);
	/*!
	 *  \brief Perform a fftshift on the fft2 given as parameter
	 *
	 */
	static void fftshift(Mat& fft2);
	/*!
	 *  \brief Return the image
	 *
	 *  \return The image
	 */
	Mat getX();
	/*!
	 *  \brief Show the magnitude of the FFT2
	 *
	 *  \param mess : The message put in the title of the windows
	 */
	void print(String mess);

	/*!
	 *  \brief Crop the spectrum if the image is not square
	 *
	 *  \param fft : The spectrum to crop
	 *
	 */
	static void cropSpectrum(Mat &fft);

	virtual ~FFT2();
};

#endif /* FFT2_H_ */

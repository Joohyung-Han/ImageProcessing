
// IMP2_HJH_200721View.cpp: CIMP2HJH200721View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "IMP2_HJH_200721.h"
#endif

#include "IMP2_HJH_200721Doc.h"
#include "IMP2_HJH_200721View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIMP2HJH200721View

IMPLEMENT_DYNCREATE(CIMP2HJH200721View, CView)

BEGIN_MESSAGE_MAP(CIMP2HJH200721View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CIMP2HJH200721View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DOWN_SAMPLING, &CIMP2HJH200721View::OnDownSampling)
	ON_COMMAND(ID_UP_SAMPLING, &CIMP2HJH200721View::OnUpSampling)
	ON_COMMAND(ID_QUANTIZATION, &CIMP2HJH200721View::OnQuantization)
	ON_COMMAND(ID_SUM_CONSTANT, &CIMP2HJH200721View::OnSumConstant)
	ON_COMMAND(ID_SUB_CONSTANT, &CIMP2HJH200721View::OnSubConstant)
	ON_COMMAND(ID_MUL_CONSTANT, &CIMP2HJH200721View::OnMulConstant)
	ON_COMMAND(ID_DIV_CONSTANT, &CIMP2HJH200721View::OnDivConstant)
	ON_COMMAND(ID_AND_OPERATE, &CIMP2HJH200721View::OnAndOperate)
	ON_COMMAND(ID_OR_OPERATE, &CIMP2HJH200721View::OnOrOperate)
	ON_COMMAND(ID_XOR_OPERATE, &CIMP2HJH200721View::OnXorOperate)
	ON_COMMAND(ID_NEGA_TRANSFORM, &CIMP2HJH200721View::OnNegaTransform)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CIMP2HJH200721View::OnGammaCorrection)
	ON_COMMAND(ID_BINARIZATION, &CIMP2HJH200721View::OnBinarization)
	ON_COMMAND(ID_STRESS_TRANSFORM, &CIMP2HJH200721View::OnStressTransform)
	ON_COMMAND(ID_HISTO_STRETCH, &CIMP2HJH200721View::OnHistoStretch)
	ON_COMMAND(ID_END_IN_SEARCH, &CIMP2HJH200721View::OnEndInSearch)
	ON_COMMAND(ID_HISTOGRAM, &CIMP2HJH200721View::OnHistogram)
	ON_COMMAND(ID_HISTO_EQUAL, &CIMP2HJH200721View::OnHistoEqual)
	ON_COMMAND(ID_HISTO_SPEC, &CIMP2HJH200721View::OnHistoSpec)
	ON_COMMAND(ID_EMBOSSING, &CIMP2HJH200721View::OnEmbossing)
	ON_COMMAND(ID_BLURR, &CIMP2HJH200721View::OnBlurr)
	ON_COMMAND(ID_GAUSSIAN_FILTER, &CIMP2HJH200721View::OnGaussianFilter)
	ON_COMMAND(ID_SHARPENING, &CIMP2HJH200721View::OnSharpening)
	ON_COMMAND(ID_HPF_SHARP, &CIMP2HJH200721View::OnHpfSharp)
	ON_COMMAND(ID_LPF_SHARP, &CIMP2HJH200721View::OnLpfSharp)
	ON_COMMAND(ID_DIFF_OPERATOR_HOR, &CIMP2HJH200721View::OnDiffOperatorHor)
	ON_COMMAND(ID_HOMOGEN_OPERATOR, &CIMP2HJH200721View::OnHomogenOperator)
	ON_COMMAND(ID_LAPLACIAN, &CIMP2HJH200721View::OnLaplacian)
	ON_COMMAND(ID_NEAREST, &CIMP2HJH200721View::OnNearest)
	ON_COMMAND(ID_BILINEAR, &CIMP2HJH200721View::OnBilinear)
	ON_COMMAND(ID_MEDIAN_SUB, &CIMP2HJH200721View::OnMedianSub)
	ON_COMMAND(ID_MEAN_SUB, &CIMP2HJH200721View::OnMeanSub)
	ON_COMMAND(ID_TRANSLATION, &CIMP2HJH200721View::OnTranslation)
	ON_COMMAND(ID_MIRROR_HOR, &CIMP2HJH200721View::OnMirrorHor)
	ON_COMMAND(ID_MIRROR_VER, &CIMP2HJH200721View::OnMirrorVer)
	ON_COMMAND(ID_ROTATION, &CIMP2HJH200721View::OnRotation)
	ON_COMMAND(ID_FRAME_SUM, &CIMP2HJH200721View::OnFrameSum)
	ON_COMMAND(ID_FRAME_SUB, &CIMP2HJH200721View::OnFrameSub)
	ON_COMMAND(ID_FRAME_MUL, &CIMP2HJH200721View::OnFrameMul)
	ON_COMMAND(ID_FRAME_DIV, &CIMP2HJH200721View::OnFrameDiv)
	ON_COMMAND(ID_FRAME_AND, &CIMP2HJH200721View::OnFrameAnd)
	ON_COMMAND(ID_FRAME_OR, &CIMP2HJH200721View::OnFrameOr)
	ON_COMMAND(ID_FRAME_COMB, &CIMP2HJH200721View::OnFrameComb)
	ON_COMMAND(ID_BINARY_EROSION, &CIMP2HJH200721View::OnBinaryErosion)
	ON_COMMAND(ID_BINARY_DILATION, &CIMP2HJH200721View::OnBinaryDilation)
	ON_COMMAND(ID_GRAY_EROSION, &CIMP2HJH200721View::OnGrayErosion)
	ON_COMMAND(ID_GRAY_DILATION, &CIMP2HJH200721View::OnGrayDilation)
	ON_COMMAND(ID_LOW_PASS_FILTER, &CIMP2HJH200721View::OnLowPassFilter)
	ON_COMMAND(ID_HIGH_PASS_FILTER, &CIMP2HJH200721View::OnHighPassFilter)
	ON_COMMAND(ID_MEAN_FILTER, &CIMP2HJH200721View::OnMeanFilter)
	ON_COMMAND(ID_MEDIAN_FILTER, &CIMP2HJH200721View::OnMedianFilter)
	ON_COMMAND(ID_MAX_FILTER, &CIMP2HJH200721View::OnMaxFilter)
	ON_COMMAND(ID_MIN_FILTER, &CIMP2HJH200721View::OnMinFilter)
	ON_COMMAND(ID_FFT_2D, &CIMP2HJH200721View::OnFft2d)
	ON_COMMAND(ID_IFFT_2D, &CIMP2HJH200721View::OnIfft2d)
	ON_COMMAND(ID_LPF_FREQUENCY, &CIMP2HJH200721View::OnLpfFrequency)
	ON_COMMAND(ID_HPF_FREQUENCY, &CIMP2HJH200721View::OnHpfFrequency)
END_MESSAGE_MAP()

// CIMP2HJH200721View 생성/소멸

CIMP2HJH200721View::CIMP2HJH200721View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CIMP2HJH200721View::~CIMP2HJH200721View()
{
}

BOOL CIMP2HJH200721View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CIMP2HJH200721View 그리기

void CIMP2HJH200721View::OnDraw(CDC* pDC)
{
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	int i, j;
	unsigned char R, G, B;
	for (i = 0; i < pDoc->m_height; i++) {
		for (j = 0; j < pDoc->m_width; j++){
			R = G = B = pDoc->m_InputImage[i * pDoc->m_width + j]; 		pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));
		}
	}
	// 축소된 영상 출력
	for (i = 0; i < pDoc->m_Re_height; i++) {
		for (j = 0; j < pDoc->m_Re_width; j++) {
			R = pDoc->m_OutputImage[i * pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}
}


// CIMP2HJH200721View 인쇄


void CIMP2HJH200721View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CIMP2HJH200721View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CIMP2HJH200721View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CIMP2HJH200721View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CIMP2HJH200721View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CIMP2HJH200721View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CIMP2HJH200721View 진단

#ifdef _DEBUG
void CIMP2HJH200721View::AssertValid() const
{
	CView::AssertValid();
}

void CIMP2HJH200721View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIMP2HJH200721Doc* CIMP2HJH200721View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIMP2HJH200721Doc)));
	return (CIMP2HJH200721Doc*)m_pDocument;
}
#endif //_DEBUG


// CIMP2HJH200721View 메시지 처리기


void CIMP2HJH200721View::OnDownSampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument(); // Doc 클래스 참조 
	ASSERT_VALID(pDoc);
	pDoc->OnDownSampling(); // Doc 클래스에 OnDownSampling 함수 호출 
	Invalidate(TRUE); // 화면 갱신

}


void CIMP2HJH200721View::OnUpSampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument(); // Doc 클래스 참조 ASSERT_VALID(pDoc);
	ASSERT_VALID(pDoc);
	pDoc->OnUpSampling(); // Doc 클래스에 OnUpSampling 함수 호출
	Invalidate(TRUE); // 화면 갱신
}


void CIMP2HJH200721View::OnQuantization()
{
	// TODO: 여기에 구현 코드 추가.
	CIMP2HJH200721Doc* pDoc = GetDocument(); // Doc 클래스 참조 ASSERT_VALID(pDoc);
	pDoc->OnQuantization(); // Doc 클래스에 OnQuantization 함수 호출
	Invalidate(TRUE); // 화면 갱신
}


void CIMP2HJH200721View::OnSumConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴
	pDoc->OnSumConstant();
	Invalidate(TRUE);
}




void CIMP2HJH200721View::OnSubConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴
	pDoc->OnSubConstant();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnMulConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴
	pDoc->OnMulConstant();
	Invalidate(TRUE);

}


void CIMP2HJH200721View::OnDivConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴
	pDoc->OnDivConstant();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnAndOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnAndOperate();
	Invalidate(TRUE);

}


void CIMP2HJH200721View::OnOrOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnOrOperate();
	Invalidate(TRUE);

}


void CIMP2HJH200721View::OnXorOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnXorOperate();
	Invalidate(TRUE);

}


void CIMP2HJH200721View::OnNegaTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnNegaTransform();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnGammaCorrection()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnGammaCorrection();
	Invalidate(TRUE);

}


void CIMP2HJH200721View::OnBinarization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnBinarization();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnStressTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnStressTransform();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnHistoStretch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistoStretch();
	Invalidate(TRUE);

}


void CIMP2HJH200721View::OnEndInSearch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnEndInSearch();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnHistogram()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistogram();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnHistoEqual()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistoEqual();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnHistoSpec()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistoSpec();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnEmbossing()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnEmbossing();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnBlurr()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnBlurr();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnGaussianFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnGaussianFilter();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnSharpening()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnSharpening();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnHpfSharp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHpfSharp();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnLpfSharp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnLpfSharp();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnDiffOperatorHor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnDiffOperatorHor();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnHomogenOperator()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHomogenOperator();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnLaplacian()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnLaplacian();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnNearest()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnNearest();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnBilinear()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnBilinear();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnMedianSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMedianSub();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnMeanSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMeanSub();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnTranslation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnTranslation();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnMirrorHor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMirrorHor();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnMirrorVer()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMirrorVer();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnRotation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnRotation();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnFrameSum()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnFrameSum();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnFrameSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnFrameSub();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnFrameMul()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnFrameMul();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnFrameDiv()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnFrameDiv();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnFrameAnd()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnFrameAnd();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnFrameOr()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnFrameOr();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnFrameComb()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnFrameComb();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnBinaryErosion()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnBinaryErosion();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnBinaryDilation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnBinaryDilation();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnGrayErosion()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnGrayErosion();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnGrayDilation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnGrayDilation();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnLowPassFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnLowPassFilter();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnHighPassFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHighPassFilter();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnMeanFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMeanFilter();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnMedianFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMedianFilter();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnMaxFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMaxFilter();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnMinFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMinFilter();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnFft2d()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnFft2d();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnIfft2d()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnIfft2d();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnLpfFrequency()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnLpfFrequency();
	Invalidate(TRUE);
}


void CIMP2HJH200721View::OnHpfFrequency()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMP2HJH200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHpfFrequency();
	Invalidate(TRUE);
}
object ImgViewer: TImgViewer
  Left = 202
  Top = 214
  Width = 113
  Height = 131
  HorzScrollBar.Tracking = True
  VertScrollBar.Tracking = True
  AutoSize = True
  BorderIcons = [biSystemMenu]
  Caption = 'Actual size image - click to close'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  ShowHint = True
  OnClick = FormClick
  PixelsPerInch = 96
  TextHeight = 13
  object Img: TImage
    Left = 0
    Top = 0
    Width = 105
    Height = 105
    AutoSize = True
    OnClick = ImgClick
  end
end

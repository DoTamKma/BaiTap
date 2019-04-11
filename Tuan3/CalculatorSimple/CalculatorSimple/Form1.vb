Public Class Form1
    
    Dim a, b, ketqua As Integer
    Dim pheptinh As String

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

    End Sub

    Private Sub txtScreen_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles txtScreen.TextChanged

    End Sub

    Private Sub cmdOne_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cmdOne.Click
        txtScreen.Text = txtScreen.Text & "1"
    End Sub

    Private Sub cmdZero_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cmdZero.Click
        If txtScreen.Text <> "0" And txtScreen.Text <> "" Then
            txtScreen.Text = txtScreen.Text & "0"
        End If
    End Sub

    Private Sub cmdTwo_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cmdTwo.Click
        txtScreen.Text = txtScreen.Text & "2"
    End Sub

    Private Sub cmdThree_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles cmdThree.Click
        txtScreen.Text = txtScreen.Text & "3"
    End Sub

    Private Sub cmdFour_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles cmdFour.Click
        txtScreen.Text = txtScreen.Text & "4"
    End Sub

    Private Sub cmFive_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles cmFive.Click
        txtScreen.Text = txtScreen.Text & "5"
    End Sub

    Private Sub cmdSix_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles cmdSix.Click
        txtScreen.Text = txtScreen.Text & "6"
    End Sub

    Private Sub cmdSeven_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles cmdSeven.Click
        txtScreen.Text = txtScreen.Text & "7"
    End Sub

    Private Sub cmdEight_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles cmdEight.Click
        txtScreen.Text = txtScreen.Text & "8"
    End Sub

    Private Sub cmdNine_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles cmdNine.Click
        txtScreen.Text = txtScreen.Text & "9"
    End Sub

    Private Sub cmdDot_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles cmdDot.Click
        If txtScreen.Text = "" Then
            txtScreen.Text = txtScreen.Text & "0."
        Else
            txtScreen.Text = txtScreen.Text & "."
        End If
    End Sub

    Private Sub cmdAC_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles cmdAC.Click
        txtScreen.Text = ""
    End Sub

    Private Sub cmdClear_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles cmdClear.Click
        txtScreen.Text = ""
    End Sub

    Private Sub cmdAdd_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles cmdAdd.Click
        a = Val(txtScreen.Text)
        txtScreen.Text = "0"
        pheptinh = "+"
    End Sub

    Private Sub cmdSub_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles cmdSub.Click
        a = Val(txtScreen.Text)
        txtScreen.Text = "0"
        pheptinh = "-"
    End Sub

    Private Sub cmdMul_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles cmdMul.Click
        a = Val(txtScreen.Text)
        txtScreen.Text = "0"
        pheptinh = "x"
    End Sub

    Private Sub cmdDiv_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles cmdDiv.Click
        a = Val(txtScreen.Text)
        txtScreen.Text = "0"
        pheptinh = "/"
    End Sub

    Private Sub cmdResult_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles cmdResult.Click
        b = Val(txtScreen.Text)
        If pheptinh = "+" Then
            ketqua = a + b
        End If
        If pheptinh = "-" Then
            ketqua = a - b
        End If
        If pheptinh = "x" Then
            ketqua = a * b
        End If
        If pheptinh = "/" Then
            ketqua = a / b
        End If
        txtScreen.Text = ketqua
    End Sub

    Private Sub cmdClose_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles cmdClose.Click
        End
    End Sub
End Class

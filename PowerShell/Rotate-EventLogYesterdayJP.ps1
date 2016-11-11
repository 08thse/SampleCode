# ������̃C�x���g���O (System) �� .evtx �t�@�C���`���ŏo�͂���

$FileName = (Get-Date).AddDays(-1).ToString("yyyy-MM-dd") + ".evtx"
$StartDay = (Get-Date).AddDays(-2).ToString("yyyy-MM-dd") + "T15:00:00.000Z"
$EndDay = (Get-Date).AddDays(-1).ToString("yyyy-MM-dd") + "T15:00:00.999Z"
$QueryString = "*[System[TimeCreated[@SystemTime>=`'" + $StartDay + "`' and @SystemTime<`'" + $EndDay + "`']]]"
wevtutil epl System $FileName /q:"$QueryString"